class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n=s.length();
        int left=0;
        int right=0;
        int maxLen=0;
        HashSet<Character> st=new HashSet<>();
        while(right<n){
            char ch=s.charAt(right);
            if(!st.contains(ch)){
                st.add(ch);
                maxLen=Math.max(maxLen,right-left+1);
                right++;
            }else{
                st.remove(s.charAt(left));
                left++;
            }
        }
        return maxLen;
    }
}