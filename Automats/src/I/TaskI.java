package I;


import java.io.*;
import java.util.InputMismatchException;
import java.util.Random;

public class TaskI {

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

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
                writer.printf("%.5f", objects[i]);
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
    private static Double[][] ans;
    private static int size;

    public static void main(String[] args) {

        Random random = new Random(System.nanoTime());

        int n = input.readInt();
        size = n * 10;
        ans = new Double[size][n];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = (double) (random.nextInt(21) - 10);
            }
        }

        while (true) {
            boolean bingo = false;
            for (int i = 0; i < size; i++) {
                String old = ask(ans[i]);
                double oldMin;
                if (old.equals("Bingo")) {
                    bingo = true;
                    break;
                }
                oldMin = Double.parseDouble(old);
                Double[] newGen = evolve(i, n);
                String new_ = ask(newGen);
                if (new_.equals("Bingo")) {
                    bingo = true;
                    break;
                }
                double newMin  = Double.parseDouble(new_);
                if (newMin < oldMin) {
                    ans[i] = newGen;
                }
            }
            if (bingo) {
                break;
            }
        }
    }

    private static Double[] evolve(int i, int n) {
        Random random = new Random();
        int v1 = random.nextInt(size);
        int v2 = random.nextInt(size);
        int v3 = random.nextInt(size);
        while (v1 == i) {
            v1 = random.nextInt(size);
        }
        while (v2 == i || v2 == v1) {
            v2 = random.nextInt(size);
        }
        while (v3 == i || v3 == v1 || v3 == v2) {
            v3 = random.nextInt(size);
        }

        Double[] res = new Double[n];
        for (int k = 0; k < n; k++) {
            res[k] = ans[v1][k] + 0.8 * (ans[v2][k] - ans[v3][k]);
            if (res[k].compareTo(10.0) > 0 || res[k].compareTo(-10.0) < 0) {
                res[k] = (double) (random.nextInt(21) - 10);
            }
        }

        for (int k = 0; k < n; k++) {
            int r = random.nextInt(100);
            if (r > 10) {
                res[k] = ans[i][k];
            }
        }
        return res;
    }

    private static String ask(Double[] point) {
        output.printLineln((Object[]) point);
        output.flush();
        return input.readString();
    }
}
//v1 + 0.8(v2 - v3)