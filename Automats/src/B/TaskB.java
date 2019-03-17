package B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class TaskB {

    public static void main(String[] args) {
        //*
        try (
                BufferedReader input = Files.newBufferedReader(Paths.get("crossover.in"));
                BufferedWriter output = Files.newBufferedWriter(Paths.get("crossover.out"))) {//*/
        /*
        try (BufferedReader input = Files.newBufferedReader(Paths.get("src\\B\\crossover.in"));
             BufferedWriter output = Files.newBufferedWriter(Paths.get("src\\B\\crossover.out"))) {//*/

            int m, n;
            String[] line = input.readLine().split(" ");
            m = Integer.parseInt(line[0]);
            n = Integer.parseInt(line[1]);
            String[] base = new String[m];
            for (int i = 0; i < m; i++) {
                base[i] = input.readLine();
            }
            String result = input.readLine();

            for (int i = 0; i < m; i++) {
                base[i] = xor(base[i], result);
            }

            { //first crossover
                int maxSuf = 0;
                int maxPref = 0;
                for (int i = 0; i < m; i++) {
                    maxPref = Math.max(maxPref, maxPref(base[i]));
                    maxSuf = Math.max(maxSuf, maxSuf(base[i]));
                }
                if (maxPref + maxSuf >= n) {
                    output.write("YES\n" +
                            "YES\n" +
                            "YES\n");
                    return;
                } else {
                    output.write("NO\n");
                }
            }
            { //second crossover
                int[] dp = new int[n];
                for (int i = 0; i < m; i++) {
                    int[] tmp = dp(base[i]);
                    for (int j = 0; j < n; j++) {
                        dp[j] = Math.max(dp[j], tmp[j]);
                    }
                }

                boolean flag = false;
                for (int i = 0; i < m; i++) {
                    int suf = maxSuf(base[i]);
                    int pref = maxPref(base[i]);
                    if (dp[pref] + suf + pref >= n) {
                        flag = true;
                        break;
                    }
                }

                if (flag) {
                    output.write("YES\n" +
                            "YES\n");
                    return;
                } else {
                    output.write("NO\n");
                }
            }

            { //third crossover
                if (n > 20) {

                    long[][] bits = new long[m][];
                    for (int i = 0; i < m; i++) {
                        bits[i] = split(base[i]);
                    }
                    for (int i = 0; i < m - 1; i++) {
                        for (int j = i + 1; j < m; j++) {
                            if (and(bits[i], bits[j])) {
                                output.write("YES\n");
                                return;
                            }
                        }
                    }
                    output.write("NO\n");
                } else {
                    int size = (int) Math.pow(2, n);
                    boolean[] dp = new boolean[size];
                    List<Integer> baseInt = new ArrayList<>();
                    for(int i = 0; i < m; i++) {
                        int t = toInt(base[i]);
                        baseInt.add(t);
                        dp[t] = true;
                    }

                    List<Integer> check = new ArrayList<>(baseInt);
                    while (!check.isEmpty()) {
                        List<Integer> tmp = new ArrayList<>();
                        for (int i : check) {
                            for (int j = 0; j < n; j++) {
                                int t = i | (1 << j);
                                if (!dp[t]) {
                                    dp[t] = true;
                                    tmp.add(t);
                                }
                            }
                        }
                        check = tmp;
                    }

                    for (int i = 0 ;i < m; i++) {
                        if (dp[baseInt.get(i) ^ ((1 << n) - 1)]) {
                            output.write("YES\n");
                            return;
                        }
                    }
                    output.write("NO\n");
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static int toInt(String s) {
        return Integer.parseInt(s, 2);
    }

    private static boolean and(long[] a, long[] b) {
        for (int i = 0; i < a.length; i++) {
            if ((a[i] & b[i]) != 0) {
                return false;
            }
        }
        return true;
    }

    private static long[] split(String s) {
        long[] ans = new long[(int) Math.ceil(s.length() / 64.0)];
        for (int i = 0; i < s.length() / 64; i++) {
            long l1 = Long.parseLong(s.substring(i * 64 + 1, (i + 1) * 64), 2);
            if (s.charAt(i * 64) == '1') {
                l1 |= Long.MIN_VALUE;
            }
            ans[i] = l1;
        }
        if (s.length() % 64 != 0) {
            long l1 = Long.parseLong(s.substring((s.length() / 64) * 64), 2);
            ans[ans.length - 1] = l1;
        }
        return ans;
    }

    private static int[] dp(String s) {
        int[] ans = new int[s.length()];
        int l = 0;
        int r = 0;
        while (l < s.length()) {
            if (r == s.length()) {
                ans[l] = (r - l);
                l++;
            } else if (l == r) {
                if (s.charAt(r) != '0') {
                    ans[l] = 0;
                    l++;
                }
                r++;
            } else {
                if (s.charAt(r) == '0') {
                    r++;
                } else {
                    ans[l] = (r - l);
                    l++;
                }
            }
        }
        return ans;
    }

    private static int maxPref(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }

    private static int maxSuf(String s) {
        int ans = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '0') {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }

    private static String xor(String a, String b) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) == b.charAt(i)) {
                ans.append('0');
            } else {
                ans.append('1');
            }
        }
        return ans.toString();
    }
}
