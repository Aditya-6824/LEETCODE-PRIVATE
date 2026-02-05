/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root == null){
            return new ArrayList<>();
        }
        List<List<Integer>> ans = new ArrayList<>();
        Stack<TreeNode> s = new Stack<>();
        s.push(root);
        int x = 0;
        
        while(!s.isEmpty()){
            int n = s.size();
            List<Integer> l = new ArrayList<>();
            Stack<TreeNode> temp = new Stack<>();
            
            for(int i = 0; i < n; i++){
                TreeNode t = s.pop();
                l.add(t.val);
                
                // Logic to control the push order for the NEXT level
                if(x % 2 == 0){
                    // If we are currently going Left-to-Right, the next level
                    // must be pushed to the stack Left then Right so it pops Right
                    // then Left.
                    if(t.left != null)
                        temp.push(t.left);
                    if(t.right != null)
                        temp.push(t.right);
                }
                else{
                    // If we are currently going Right-to-Left, the next level
                    // must be pushed Right then Left so it pops Left then
                    // Right.
                    if(t.right != null)
                        temp.push(t.right);
                    if(t.left != null)
                        temp.push(t.left);
                }
            }
            ans.add(l);
            s = temp; // Move to next level
            x++;      // Switch direction
        }
        return ans;
    }
}