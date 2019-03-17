package E;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class TaskE {

    public static void main(String[] args) {
        //*
        try (BufferedReader input = Files.newBufferedReader(Paths.get("discrete.in"));
             BufferedWriter output = Files.newBufferedWriter(Paths.get("discrete.out"))) {//*/
        /*
        try (BufferedReader input = Files.newBufferedReader(Paths.get("src\\E\\discrete.in"));
             BufferedWriter output = Files.newBufferedWriter(Paths.get("src\\E\\discrete.out"))) {//*/

            int n, m;
            String[] firstLine = input.readLine().split("\\s+");
            n = Integer.parseInt(firstLine[0]);
            m = Integer.parseInt(firstLine[1]);

            List<Node> automat = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                automat.add(null);
            }
            for (int i = 0; i < n; i++) {
                String[] line =  input.readLine().split("\\s+");
                int e0 = Integer.parseInt(line[0]) - 1;
                int e1 = Integer.parseInt(line[1]) - 1;
                automat.set(i, new Node(i, e0, e1));
            }

            for (int i = 0; i < m; i++) {
                String[] line = input.readLine().split("\\s+");
                int size = Integer.parseInt(line[0]);
                double len = 1.0 / size;
                Node tmp = automat.get(0);
                for (int j = 0; j < size; j++) {
                    int ind = line[2].charAt(j) - 'a';
                    if (line[1].charAt(j) == '0') {
                        double val = tmp.e0alph.get(ind);
                        val += len;
                        tmp.e0alph.set(ind, val);
                        tmp = automat.get(tmp.e0);
                    } else {
                        double val = tmp.e1alph.get(ind);
                        val += len;
                        tmp.e1alph.set(ind, val);
                        tmp = automat.get(tmp.e1);
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                StringBuilder out = new StringBuilder();
                Node tmp = automat.get(i);
                int ind = 0;
                double max = 0.0;
                for (int j = 0; j < 26; j++) {
                    if (tmp.e0alph.get(j).compareTo(max) > 0 ) {
                        ind = j;
                        max = tmp.e0alph.get(j);
                    }
                }
                out.append((char) ('a' + ind));
                out.append(' ');

                ind = 0;
                max = 0.0;
                for (int j = 0; j < 26; j++) {
                    if (tmp.e1alph.get(j).compareTo(max) > 0 ) {
                        ind = j;
                        max = tmp.e1alph.get(j);
                    }
                }
                out.append((char) ('a' + ind));
                out.append('\n');
                output.write(out.toString());
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static class Node {
        int num;
        int e0, e1;
        List<Double> e0alph = new ArrayList<>(26);
        List<Double> e1alph = new ArrayList<>(26);

        public Node(int num, int e0, int e1) {
            this.num = num;
            this.e0 = e0;
            this.e1 = e1;
            for (int i = 0; i < 26; i++) {
                e0alph.add(0.0);
                e1alph.add(0.0);
            }
        }
    }
}
