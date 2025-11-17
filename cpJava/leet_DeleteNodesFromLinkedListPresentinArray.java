package offl.leetcodes;

import java.util.HashSet;

public class leet_DeleteNodesFromLinkedListPresentinArray {

    // Definition for singly-linked list.
    public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
   }

    private ListNode afterDeletion(HashSet<Integer> hs, ListNode curr){

        if(curr == null){
            return null;
        }

        ListNode ch = afterDeletion(hs, curr.next);

        if(hs.contains(curr.val) ){
            //delete current node

            //then return
            return ch;
        }

        curr.next = ch;
        return curr;
    }

    public ListNode modifiedList(int[] nums, ListNode head) {
        HashSet<Integer> hs = new HashSet<>();
        for(int num: nums){
            hs.add(num);
        }
        return afterDeletion(hs,head);
    }


}
