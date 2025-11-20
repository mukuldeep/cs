package offl.leetcodes;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;

public class leet_SetIntersectionSizeAtLeastTwo {

    static class Pair<U, V> {
        public final U first;
        public final V second;

        public Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public String toString() {
            return "(" + first + ", " + second + ")";
        }

    }

    public static int intersectionSizeTwo(int[][] intervals) {

        ArrayList<Pair<Integer,Integer>> starts = new ArrayList<>();
        ArrayList<Pair<Integer,Integer>> ends = new ArrayList<>();

        for(int i=0; i<intervals.length; i++){
            starts.add(new Pair<>(intervals[i][0],i));
            ends.add(new Pair<>(intervals[i][1],i));
        }

        Collections.sort(starts,(a, b) -> {
            int cmp = Integer.compare(a.first, b.first);
            if (cmp != 0) return cmp;
            return Integer.compare(a.second, b.second);
        });

        Collections.sort(ends,(a, b) -> {
            int cmp = Integer.compare(a.first, b.first);
            if (cmp != 0) return cmp;
            return Integer.compare(a.second, b.second);
        });

        int[] intervalInd2startSetInd = new int[intervals.length];

        System.out.println(" starts: ");
        int xx = 0;
        for(Pair<Integer,Integer> start: starts){
            System.out.print(" ("+start.first+","+start.second+") ");
            intervalInd2startSetInd[start.second] = xx;
            xx++;
        }System.out.println();

        System.out.println(" ends: ");
        for(Pair<Integer,Integer> start: ends){
            System.out.print(" ("+start.first+","+start.second+") ");
        }System.out.println();

        HashSet<Integer>[] ansSets = new HashSet[intervals.length];
        for(int i=0; i<intervals.length; i++){
            ansSets[i] = new HashSet<>();
        }

        HashSet<Integer> firstSetInd = new HashSet<>();
        HashSet<Integer> ansSet = new HashSet<>();

        int i=0, j=0;
        for(; i<starts.size() && j<ends.size(); ){

            if(starts.get(i).first <= ends.get(j).first){
                System.out.println("\tprocess start:"+starts.get(i));
                firstSetInd.add(i);
                i++;
            }else{
                System.out.println("\tprocess end:"+ends.get(j) +" setCnt:"+ansSets[ends.get(j).second].size() );
                if(ansSets[ends.get(j).second].size() < 2){
                    boolean res = firstSetInd.remove(intervalInd2startSetInd[ends.get(j).second]);//wrong
                    System.out.println("\t\tremoving :"+ends.get(j)+"i.e. "+intervalInd2startSetInd[ends.get(j).second]+" "+res);

                    int a = ends.get(j).first;
                    ansSet.add(a);
                    ansSets[ends.get(j).second].add(a);

                    for(Integer prInd: firstSetInd){
                        System.out.println("\t\t\tfirstSetInd "+prInd);
                        if( intervals[starts.get(prInd).second][0] <= a && a <= intervals[starts.get(prInd).second][1]){
                            System.out.println("\t\t\t\tadding "+a+" to "+starts.get(prInd));
                            ansSets[starts.get(prInd).second].add(a);
                        }
                    }

                    System.out.println("\t\t a-1:"+(a-1)+" setCnt:"+ansSets[ends.get(j).second].size()+"  ends:"+ends.get(j) );

                    if(ansSets[ends.get(j).second].size() < 2){
                        ansSet.add(a-1);
                        ansSets[ends.get(j).second].add((a-1));
                        for(Integer prInd: firstSetInd){
                            System.out.println("\t\t\tfirstSet ind:"+prInd+" fsEl:"+starts.get(prInd));
                            if( intervals[starts.get(prInd).second][0] <= (a-1) && (a-1) <= intervals[starts.get(prInd).second][1]){
                                System.out.println("\t\t\t\tadding "+(a-1)+" to "+starts.get(prInd).second);
                                ansSets[starts.get(prInd).second].add((a-1));
                            }
                        }
                    }

                }
                else{
                    System.out.println("\t\tnothing to do! already satisfied!");
                }

                j++;
            }
        }

        System.out.println("2nd #############");
        for(; j<ends.size(); ){

            System.out.println("\tprocess end:"+ends.get(j).first +" setCnt:"+ansSets[ends.get(j).second].size() );
            if(ansSets[ends.get(j).second].size() < 2){
                boolean res = firstSetInd.remove(intervalInd2startSetInd[ends.get(j).second]);
                System.out.println("\t\tremoving index:"+ends.get(j).second+" "+res);

                int a = ends.get(j).first;
                ansSet.add(a);
                ansSets[ends.get(j).second].add(a);

                for(Integer prInd: firstSetInd){
                    System.out.println("\t\tf "+starts.get(prInd).second);
                    if( intervals[starts.get(prInd).second][0] <= a && a <= intervals[starts.get(prInd).second][1]){
                        System.out.println("\t\t\tadding "+a+" to "+starts.get(prInd).second);
                        ansSets[starts.get(prInd).second].add(a);
                    }
                }

                System.out.println("\t\t a-1:"+(a-1)+" setCnt:"+ansSets[ends.get(j).second].size() );

                if(ansSets[ends.get(j).second].size() < 2){
                    ansSet.add(a-1);
                    ansSets[ends.get(j).second].add(a-1);

                    for(Integer prInd: firstSetInd){
                        if( intervals[starts.get(prInd).second][0] <= (a-1) && (a-1) <= intervals[starts.get(prInd).second][1]){
                            System.out.println("\t\t\tadding "+(a-1)+" to "+starts.get(prInd).second);
                            //setCnt[starts.get(prInd).second]++;
                            ansSets[starts.get(prInd).second].add((a-1));
                        }
                    }
                }

            }
            else{
                System.out.println("\t\tnothing to do! already satisfied!");
            }

            j++;

        }

        System.out.print("ansSet:");
        for(int ansInt: ansSet){
            System.out.print(" "+ansInt);
        }System.out.println();

        return ansSet.size();
    }

    public static void main(String[] args){
        int[][] nums = {{1,3},{3,7},{8,9}};

        //int[][] nums = {{1,3},{1,4},{2,5},{3,5}};
        //int[][] nums = {{8,10},{2,4},{4,5}};
        //int[][] nums = {{1,3},{3,7},{5,7},{7,8}};

        int ans = intersectionSizeTwo(nums);
        System.out.println("ans="+ans);

    }
}
