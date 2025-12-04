package offl.contest;

public class leet_CountCollisionsonaRoad {

    public static int countCollisions(String directions) {
        int cnt = 0;
        for(char ch: directions.toCharArray()){
            if(ch != 'S'){
                cnt++;
            }
        }

        for(char ch: directions.toCharArray()){
            if(ch != 'L'){
                break;
            }
            cnt--;
        }

        for(int i=directions.length()-1; i>=0; i--){
            if(directions.charAt(i) != 'R'){
                break;
            }
            cnt--;
        }

        return cnt;
    }

    public static void main(String[] args){

        String dir = "LRSRLRLRLLRLRLSLSLSLRLSLRLSLRLSLRLSLRLSL";

        System.out.println(countCollisions(dir));
    }
}
