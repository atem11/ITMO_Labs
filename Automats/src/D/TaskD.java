package D;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class TaskD {
    public static void main(String[] args) {
        //*
        try (BufferedReader input = Files.newBufferedReader(Paths.get("start.in"));
             BufferedWriter output = Files.newBufferedWriter(Paths.get("start.out"))) {//*/
        /*
        try (BufferedReader input = Files.newBufferedReader(Paths.get("src\\D\\start.in"));
             BufferedWriter output = Files.newBufferedWriter(Paths.get("src\\D\\start.out"))) {//*/

            int len, cnt;
            String[] firstLine = input.readLine().split("\\s+");
            len = Integer.parseInt(firstLine[0]);
            cnt = Integer.parseInt(firstLine[1]);

            Node[] automate = new Node[cnt];
            for (int i = 0; i < cnt; i++) {
                automate[i] = new Node(i);
            }

            for (int ind = 0; ind < cnt; ind++) {
                String[] line = input.readLine().split("\\s+");
                int out0 = Integer.parseInt(line[0]);
                int out1 = Integer.parseInt(line[1]);

                automate[ind].symbol = line[2].charAt(0);
                automate[ind].way0 = out0 - 1;
                automate[ind].way1 = out1 - 1;
            }
            String out = input.readLine();

            boolean[] markFin = new boolean[cnt];
            char c = out.charAt(len - 1);
            for (int i = 0; i < cnt; i++) {
                if (automate[i].symbol == c) {
                    markFin[i] = true;
                }
            }

            for (int i = len - 1; i >= 0; i--) {
                char ch = out.charAt(i);
                boolean[] mark = new boolean[cnt];
                for (int n = 0; n < cnt; n++) {
                    Node node = automate[n];
                    if (automate[node.way0].symbol == ch && markFin[node.way0]) {
                        mark[node.num] = true;
                    }
                    if (automate[node.way1].symbol == ch && markFin[node.way1]) {
                        mark[node.num] = true;
                    }
                }
                markFin = mark;
            }

            int ans = 0;
            for (int i = 0; i < cnt; i++) {
                if (markFin[i]) {
                    ans++;
                }
            }
            output.write(String.valueOf(ans));
            StringBuilder o = new StringBuilder();
            for (int i = 0; i < cnt; i++) {
                if (markFin[i]) {
                    o.append(" ").append(i + 1);
                }
            }
            output.write(o.toString());

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class Node {
    int num;

    int way0;
    int way1;
    char symbol;

    Node(int num) {
        this.num = num;
    }
}