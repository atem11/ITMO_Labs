package G;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class TaskG {

    public static void main(String[] args) {
        //*
        try (BufferedReader input = Files.newBufferedReader(Paths.get("artificial.in"));
             BufferedWriter output = Files.newBufferedWriter(Paths.get("artificial.out"))) {//*/
        /*
        try (BufferedReader input = Files.newBufferedReader(Paths.get("src\\G\\artificial.in"));
             BufferedWriter output = Files.newBufferedWriter(Paths.get("src\\G\\artificial.out"))) {//*/

            String test = input.readLine();
            switch (test){
                case "1":
                    output.write("2 1 R M\n");
                    output.write("3 3 M M\n");
                    output.write("3 4 R M\n");
                    output.write("2 2 L M\n");
                    break;
                case "2":
                    output.write("1 1 R M\n");
                    break;
                case "3":
                    output.write("3 3 R M\n");
                    output.write("3 3 L M\n");
                    output.write("1 2 M M\n");
                    break;
                case "4":
                    output.write("4 4 R M\n");
                    output.write("1 3 M M\n");
                    output.write("4 3 L M\n");
                    output.write("2 4 M M\n");
                    break;
                case "5":
                    output.write("3 2 M M\n");
                    output.write("1 1 R M\n");
                    output.write("2 3 M L\n");
                    break;
                case "6":
                    output.write("3 5 M M\n");
                    output.write("4 1 M M\n");
                    output.write("5 1 R M\n");
                    output.write("2 1 L M\n");
                    output.write("4 2 M M\n");
                    break;
                case "7":
                    output.write("2 2 L M\n");
                    output.write("2 3 R M\n");
                    output.write("1 4 M M\n");
                    output.write("2 3 M M\n");
                    break;
                case "8":
                    output.write("5 2 M M\n");
                    output.write("3 2 M M\n");
                    output.write("4 4 R M\n");
                    output.write("5 2 R M\n");
                    output.write("1 1 R M\n");
                    break;
                case "9":
                    output.write("2 3 R M\n");
                    output.write("4 4 L M\n");
                    output.write("5 4 M M\n");
                    output.write("5 6 L M\n");
                    output.write("6 1 R M\n");
                    output.write("1 3 M M\n");
                    break;
                case "10":
                    output.write("3 4 R M\n");
                    output.write("1 1 M M\n");
                    output.write("5 6 R M\n");
                    output.write("6 1 R M\n");
                    output.write("2 1 R M\n");
                    output.write("2 5 L M\n");
                    break;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
