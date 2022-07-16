package Keno;

import java.util.Set;

public class GM {
    public static final String BLACK = "\033[0;30m";   // BLACK
    public static final String RED = "\033[0;31m";     // RED
    public static final String GREEN = "\033[0;32m";   // GREEN
    public static final String YELLOW = "\033[0;33m";  // YELLOW
    public static final String BLUE = "\033[0;34m";    // BLUE
    public static final String PURPLE = "\033[0;35m";  // PURPLE
    public static final String CYAN = "\033[0;36m";    // CYAN
    public static final String WHITE = "\033[0;37m";   // WHITE
    public static final String RESET = "\033[0m";

    public void start(Bet bet) {
        System.out.println(">>> Starting the game.");
        System.out.println("    Going for a total of " + bet.getRounds() + " rounds, waging " + bet.getBetPerRound() + " per round.");
        System.out.println(GREEN + "    ------+-------" + RESET);
        System.out.println(GREEN + "    Hits  | Payout" + RESET);
        System.out.println(GREEN + "    ------+-------" + RESET);
        Payout showPayout = new Payout();

        for(int i = 0; i <= bet.getSize(); i++) {
            System.out.println("    " + i + "    | " + showPayout.getPayoutRate(bet.getSize(),i)+ "       ");
        }

        for(int i = 1; i <= bet.getRounds(); i++) {
            System.out.println("------------------------------------------------");
            System.out.println(GREEN + "    This is round #" + i + ", and your bet is $" + bet.getBetPerRound() + "." + RESET);

            // create draw
            Draw draw = new Draw();
            draw.makeDraw();
            draw.showDraw();

            // calculate hits
            Hits hits = new Hits();
            hits.calculateHits(draw.getDraw(), bet.getSpots());
            hits.showHits(bet.getSize());

            // calculate payout
            Payout payout = new Payout();
            payout.getPayoutRate(bet.getSpots().size(),hits.getHits());
            payout.showPayout(bet.getBetPerRound());

            // update wage
            bet.setWage(bet.getWage() - bet.getBetPerRound() + payout.getTotalPayout());
            bet.showWage();

            if(i == bet.getRounds()) {
                System.out.println(">>> End of rounds!");
                System.out.println("------------------------------------------------");
            }
        }
    }

    public void summary(Bet bet) {
        System.out.println("===== SUMMARY =====");
        System.out.println(">>> You spent in this game a total of $" + bet.getBetValue() + ".");
        if(bet.getWage() > bet.getBetValue()) {
            System.out.println(">>> Hooray, you won $" + (bet.getWage() - bet.getBetValue()) + ". See you next time!");
        } else if(bet.getWage() == bet.getBetValue()) {
            System.out.println(">>> You won $0. Or did you lose $0? Half-full or half-empty? Anyway, see you next time!");
        } else {
            System.out.println(">>> Oops... you lost $" + (bet.getBetValue() - bet.getWage()) + ". See you (hopefully with more luck) next time!");
        }
        System.out.println(">>> You are leaving the Keno table with $" + bet.getWage() + ".");
    }
}
