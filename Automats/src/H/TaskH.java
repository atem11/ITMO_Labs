package H;

import java.io.*;
import java.util.InputMismatchException;

public class TaskH {

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0)
                    writer.print(' ');
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
        }

        public void printLineln(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void flush() {
            writer.flush();
        }
    }

    private static InputReader input = new InputReader(System.in);
    private static OutputWriter output = new OutputWriter(System.out);
    private static int ITERATION = 10;

    public static void main(String[] args) {

        int n = input.readInt();
        Double[] ans = new Double[n];
        for (int i = 0; i < n; i++) {
            ans[i] = 0.0;
        }
        double globalMin = ask(ans);

        for (int i = 0; i < n; i++) {

            for (int part = 0; part < 20; part++) {
                double l = part / 20.0;
                double r = (part + 1) / 20.0;
                double ansVal = l;
                double min = ask(i, l, ans);
                double minR = ask(i, r, ans);

                if (min > minR) {
                    min = minR;
                    ansVal = r;
                }

                for (int iter = 0; iter < ITERATION; iter++) {
                    double m1 = (r + 2 * l) / 3.0;
                    double m2 = (2 * r + l) / 3.0;
                    double m1Ans = ask(i, m1, ans);
                    double m2Ans = ask(i, m2, ans);

                    if (m1Ans > m2Ans) {
                        l = m1;
                    } else {
                        r = m2;
                    }
                }

                minR =  ask(i, l, ans);
                if (min > minR) {
                    min = minR;
                    ansVal = l;
                }


                if (min < globalMin) {
                    globalMin = min;
                    ans[i] = ansVal;
                }
            }
        }
        output.printLineln("minimum", globalMin);
        output.flush();
    }

    private static double ask(int ind, double val, Double[] point) {
        double old = point[ind];
        point[ind] = val;
        double ans = ask(point);
        point[ind] = old;
        return ans;
    }

    private static double ask(Double[] point) {
        output.printLineln((Object[]) point);
        output.flush();
        return Double.parseDouble(input.readString());
    }
}
