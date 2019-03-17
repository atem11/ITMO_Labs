package C;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class TaskC {

    public static void main(String[] args) {
        //*
        try (BufferedReader input = Files.newBufferedReader(Paths.get("trees.in"));
             BufferedWriter output = Files.newBufferedWriter(Paths.get("trees.out"))) {//*/
        /*
        try (BufferedReader input = Files.newBufferedReader(Paths.get("src\\C\\trees.in"));
             BufferedWriter output = Files.newBufferedWriter(Paths.get("src\\C\\trees.out"))) {//*/

            int k = Integer.parseInt(input.readLine());
            List<Tree> tree = new ArrayList<>();
            for (int node = 0; node < k; node++) {
                String[] line = input.readLine().split(" ");
                if (line[0].equals("leaf")) {
                    tree.add(new Tree(Integer.parseInt(line[1])));
                } else {
                    tree.add(new Tree(
                            Integer.parseInt(line[1]) - 1,
                            Integer.parseInt(line[2]) - 1,
                            Integer.parseInt(line[3]) - 1
                    ));
                }
            }
            Tree root = tree.get(0);
            for (int ind = 0; ind < k; ind++) {
                Tree tmpTree = tree.get(ind);
                if (!tmpTree.isLeaf()) {
                    tmpTree.addChilds(
                            tree.get(tmpTree.son1()),
                            tree.get(tmpTree.son2())
                    );
                }
            }

            root.deleteBranch(new HashMap<>());

            //OUTPUT
            output.write(String.valueOf(root.renum()));
            output.newLine();
            root.toString(output);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}

class Tree {

    private int num;
    private boolean typeLeaf = false;
    private int s0, s1;
    private int predicate;
    private int value;

    private Tree parent = null;
    private Tree child0;
    private Tree child1;

    Tree(int value) {
        this.value = value;
        typeLeaf = true;
    }

    Tree(int predicate, int son0, int son1) {
        this.predicate = predicate;
        s0 = son0;
        s1 = son1;
    }

    void addChilds(Tree s0, Tree s1) {
        child0 = s0;
        child1 = s1;
        child0.parent = this;
        child1.parent = this;
    }

    boolean isLeaf() {
        return typeLeaf;
    }

    int son1() {
        return s0;
    }

    int son2() {
        return s1;
    }

    int renum() {
        return renum(1) - 1;
    }

    private int renum(int num) {
        this.num = num;
        num++;
        if (!typeLeaf) {
            num = child0.renum(num);
            num = child1.renum(num);
            s0 = child0.num;
            s1 = child1.num;
        }
        return num;
    }

    void toString(BufferedWriter writer) throws IOException {
        if (typeLeaf) {
            writer.write("leaf " + (value) + "\n");
        } else {
            writer.write("choice " + (predicate + 1) + " " + s0 + " " + s1 + "\n");
            child0.toString(writer);
            child1.toString(writer);
        }
    }

    void deleteBranch(Map<Integer, Integer> pred) {
        if (!typeLeaf) {
            if (pred.containsKey(predicate)) {
                if (pred.get(predicate) == 0) {
                    //delete 1 branch
                    if (parent.child0 == this) {
                        parent.child0 = child0;
                    } else {
                        parent.child1 = child0;
                    }
                    child0.parent = parent;
                    child0.deleteBranch(pred);
                } else {
                    //delete 0 branch
                    if (parent.child0 == this) {
                        parent.child0 = child1;
                    } else {
                        parent.child1 = child1;
                    }
                    child1.parent = parent;
                    child1.deleteBranch(pred);
                }
            } else {
                pred.put(predicate, 0);
                child0.deleteBranch(pred);
                pred.remove(predicate, 0);

                pred.put(predicate, 1);
                child1.deleteBranch(pred);
                pred.remove(predicate, 1);
            }
        }
    }
}