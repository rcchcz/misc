rootProject.name = 'Keno'

package Keno;

import java.io.IOException;
import java.util.*;

import static java.lang.System.exit;

public class Bet {
    private double wage;
    private double betValue;
    private int numRounds;
    private double betPerRound;
    private Set<Integer> spots = new HashSet<>();
    Scanner scan = new Scanner(System.in);
    private int betSize;

    public void setBetSize() {
        this.betSize = getSpots().size();
    }

    public void setWage(double wage){
        this.wage = wage;
    }

    public <T extends GameMode> Set<Integer> create(T betObj){
        return  betObj.setSpots();
    }

    public void setGameMode() throws IOError{
        System.out.println(">>> Press 1 to play standard game mode and 2 to play random mode.");

        int gameMode = scan.nextInt();

        if(gameMode == 1){
            DefaultSpots defaultSpots = new DefaultSpots();
            spots = create(defaultSpots);
            setBetSize();
        } else if(gameMode == 2) {
            RandomSpots randomSpots = new RandomSpots();
            spots = create(randomSpots);
            setBetSize();
        } else {
            throw new IOError();
        }
    }

    public void setBetValue() {
        System.out.println(">>> Insert your bet value: ");
        betValue = scan.nextInt();
        wage = betValue;
    }

    public void setnumRounds() {
        System.out.println(">>> Insert the number of rounds you want to play: ");
        numRounds = scan.nextInt();
        if(numRounds <= 0){
            numRounds = 1;
        }
        betPerRound = betValue/numRounds;
    }

    public double getWage() {
        return wage;
    }

    public int getSize() {
        return betSize;
    }

    public Set<Integer> getSpots() {
        return spots;
    }

    public int getRounds() {
        return numRounds;
    }

    public double getBetValue() {
         return betValue;
    }

    public double getBetPerRound() {
        return betPerRound;
    }

    public void startSummary() {
        System.out.println();
        System.out.println(">>> Bet successfully read!");
        System.out.println("    Total bet: " + betValue);
        System.out.println("    Rounds: " + numRounds);
        System.out.println("    Bet per round: " + betPerRound);
        System.out.println("    Your spots: " + spots);
        System.out.println();
        System.out.println(">>> Do you want to confirm the bet? Y/N");
        String opt = scan.next();
        if("N".equals(opt)) {
            System.out.println(">>> Insert 1 to redo your bet or 2 to leave the game?");
            if(scan.nextInt() == 1) {
                spots.clear();
                setBetValue();
                setnumRounds();
                //setSpots();
                startSummary();
            } else {
                exit(0);
            }
        } else if("Y".equals(opt)) {
            GM gm = new GM();
            gm.start(this);
            gm.summary(this);
        }
    }

    public void showWage(){
        System.out.println("    Your balance so far is: $" + wage + ".");
    }
}
