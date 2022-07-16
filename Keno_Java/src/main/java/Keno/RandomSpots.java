package Keno;

import java.util.*;

public class RandomSpots implements GameMode {
    Random random = new Random();
    int betSize = random.nextInt(15)+1;
    Set<Integer> spots = new TreeSet<>();

    public Set<Integer> setSpots(){
        int count = 0;
        while(count < betSize) {
            if(spots.add((random.nextInt(80)+1))) {
                count++;
            }
        }
        return spots;
    }
}
