package A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.DecimalFormat;

public class TaskA {

    public static void main(String[] args) {
        DecimalFormat out = new DecimalFormat("#0.000000000");
        //*
        try (BufferedReader input = Files.newBufferedReader(Paths.get("mutation.in"));
             BufferedWriter output = Files.newBufferedWriter(Paths.get("mutation.out"))) {//*/
        /*
        try (BufferedReader input = Files.newBufferedReader(Paths.get("src\\A\\mutation.in"));
             BufferedWriter output  = Files.newBufferedWriter(Paths.get("src\\A\\mutation.out"))) {//*/
            int n, m;
            String[] firstLine = input.readLine().split(" ");
            n = Integer.parseInt(firstLine[0]);
            m = Integer.parseInt(firstLine[1]);
            double p = 1.0 / n;
            double q = ((double) (n - 1)) / n;
            for (int ind = 0; ind < m; ind++) {
                String s = input.readLine();
                String t = input.readLine();
                double ans = 1.0;
                for (int ch = 0; ch < n; ch++) {
                    if (s.charAt(ch) != t.charAt(ch)) {
                        ans *= p;
                    } else {
                        ans *= q;
                    }
                }
                output.write(out.format(ans));
                output.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
