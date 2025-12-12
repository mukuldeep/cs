package offl.contest;

import java.util.*;

public class leet_CountMentionsPerUser {


    public static int[] countMentions(int numberOfUsers, List<List<String>> events) {
        int[] mentionCnt = new int[numberOfUsers];
        int allCnt = 0;

        PriorityQueue<List<String>> pq = new PriorityQueue<>((a, b) -> {
            int cmp = Integer.compare(
                    Integer.parseInt(a.get(1)),
                    Integer.parseInt(b.get(1))
            );
            if (cmp != 0) return cmp;

            return b.get(0).compareTo(a.get(0)); // tie → compare by first element
        });

        for(List<String> event : events){
            if(event.get(0).equals("MESSAGE")){
                if(event.get(2).equals("ALL")){
                    allCnt++;
                }else if(event.get(2).equals("HERE")){
                    pq.add(event);
                }else{
                    String[] mentions = event.get(2).split(" ");
                    for(String mention: mentions){
                        if(mention.length()>2){
                            int userId = Integer.parseInt(mention.substring(2));
                            mentionCnt[userId]++;
                        }
                    }

                }

            }else{
                pq.add(event);
                List<String> online = new ArrayList<>();
                online.add("ONLINE");
                online.add(String.valueOf(Integer.parseInt(event.get(1))+60));
                online.add(event.get(2));
                pq.add(online);
            }
        }

        boolean[] onlineUsers = new boolean[numberOfUsers];
        Arrays.fill(onlineUsers,true);

        while(!pq.isEmpty()){
            List<String> event = pq.remove();
            //System.out.println(event);

            if(event.get(0).equals("MESSAGE")){
                for(int i=0;i<numberOfUsers;i++){
                    if(onlineUsers[i]){
                        mentionCnt[i]++;
                    }
                }
            }else{
                onlineUsers[Integer.parseInt(event.get(2))] = event.get(0).equals("OFFLINE")?false:true;
            }
        }

        if(allCnt>0){
            for(int i=0;i<numberOfUsers;i++){
                mentionCnt[i]+=allCnt;
            }
        }

        return mentionCnt;
    }


        public static void main(String[] args){
            long num1 = 42;

            int numberOfUsers = 2;
            String[][] events = {{"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","71","HERE"}};

            List<List<String>> list = new ArrayList<>();
            for (String[] row : events) {
                list.add(Arrays.asList(row));
            }
            int[] ans = countMentions(numberOfUsers,list);
            System.out.println("Output: " + Arrays.toString(ans));

            System.out.println();
        }
}
