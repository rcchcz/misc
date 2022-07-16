package Keno;

import java.util.HashSet;
import java.util.Random;
import java.util.Set;
import java.util.TreeSet;

public class Draw {
    static int MAX_OF_DRAW = 20;
    private Set<Integer> draw = new TreeSet<>();

    public void makeDraw() {
        Random random = new Random();
        int count = 0;
        while(count < MAX_OF_DRAW) {
            if(draw.add((random.nextInt(80)+1))) {
                count++;
            }
        }
    }

    public void showDraw() {
        System.out.println("    The draw numbers are: ");
        System.out.println("    " + draw);
    }

    public Set<Integer> getDraw() {
        return draw;
    }
}
