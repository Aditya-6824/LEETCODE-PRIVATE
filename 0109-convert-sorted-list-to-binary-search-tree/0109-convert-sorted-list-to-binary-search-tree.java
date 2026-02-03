/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        if(head==null ) return null;
        if(head.next==null) return new TreeNode(head.val);

        ListNode temp = head;
        return making(temp);
    }
    public TreeNode making (ListNode temp){
        if(temp==null) return null;

        ListNode slow = temp , fast = temp ,prev= null;

        while(fast!=null && fast.next!=null){
            prev = slow;
            slow = slow.next ;
            fast =fast.next.next;
        } 
        TreeNode root = new TreeNode (slow.val);

        if(prev!=null){
            prev.next = null;
        root.left = making(temp);
        }

        root.right = making(slow.next);
        return root;
    }

}