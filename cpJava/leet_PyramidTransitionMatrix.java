package offl.contest;

import java.util.*;

public class leet_PyramidTransitionMatrix {


    public static void createAllString(String base, int ind, String word, HashSet<String> hs, HashMap<String, ArrayList<Character>> mp){
        if(ind == base.length()){
            hs.add(word);
            return;
        }

        String key = base.substring(ind-1,ind+1);
        if(mp.containsKey(key)) {
            for (Character ch : mp.get(key)) {
                createAllString(base, ind + 1, word + ch, hs, mp);
            }
        }
    }

    public static HashSet<String> getAllStrings(String base, HashMap<String, ArrayList<Character>> mp){
        HashSet<String> hs = new HashSet<>();
        createAllString(base, 1, "", hs, mp);

        System.out.print(base+" next_base: ");
        for(String str: hs){
            System.out.print(str+" ");
        }
        System.out.println();

        return hs;
    }




    public static boolean pyramidTransition(String bottom, List<String> allowed) {

        HashMap<String, ArrayList<Character>> mp = new HashMap<>();
        for(String allStr : allowed){
            if(!mp.containsKey(allStr.substring(0,2))) {
                mp.put(allStr.substring(0, 2), new ArrayList<Character>());
            }
            mp.get(allStr.substring(0,2)).add(allStr.charAt(2));
        }

        for(String key : mp.keySet()){
            System.out.println("baseTRI:"+key);
        }
        System.out.println();

        HashSet<String> preHs = new HashSet<>();
        preHs.add(bottom);


        for(int i=bottom.length(); i>1; i--) {
            HashSet<String> hs = new HashSet<>();
            for (String str : preHs) {
                HashSet<String> hsTemp = getAllStrings(str, mp);
                hs.addAll(hsTemp);
            }

            if(hs.isEmpty()){
                return false;
            }

            preHs = hs;
        }

        return true;
    }


    public static void main(String[] args){

//        String bottom = "BCD";
//        String[] allowed = {"BCC","CDE","CEA","FFF"};

        String bottom = "BCDAEF";
        String[] allowed = {"BCC","CDE","CEA","FFF","AEF","DAE","DAF","DAA","DAB","DBB","CDF","EFA","EFB","EFC","EFD","EFE","EFF"};

//        String bottom = "AAAA";
//        String[] allowed = {"AAB","AAC","BCD","BBE","DEF"};

        System.out.println(pyramidTransition(bottom, Arrays.asList(allowed)));


    }
}
