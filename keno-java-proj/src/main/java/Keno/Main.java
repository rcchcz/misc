package Keno;

public class Main {
    public static void main(String[] args) throws IOError {
        // create bet
        Bet kenoBet = new Bet();
        kenoBet.setBetValue();
        kenoBet.setnumRounds();
        kenoBet.setGameMode();
        kenoBet.startSummary();
    }
}