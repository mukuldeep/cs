package offl.contest;

public class leet_FindtheWinningPlayerinCoinGame {

    public String winningPlayer(int x, int y) {

        int totalSet = Math.min(x,y/4);
        if((totalSet&1) == 1){
            return "Alice";
        }
        return "Bob";

    }

}
