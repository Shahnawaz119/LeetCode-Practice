class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.length();
        int result1=0;
        int count_false=0;
        int start1=0;
        for(int end=0; end<n; end++){
            if(answerKey[end]=='F'){
                count_false++;
            }
            while(count_false>k){
                if(answerKey[start1]=='F'){
                    count_false--;
                }
                start1++;
            }
            result1=max(result1,end-start1+1);
        }
        int result2=0;
        int count_true=0;
        int start2=0;
        for(int end=0; end<n; end++){
            if(answerKey[end]=='T'){
                count_true++;
            }
            while(count_true>k){
                if(answerKey[start2]=='T'){
                    count_true--;
                }
                start2++;
            }
            result2=max(result2,end-start2+1);
        }
        return max(result1,result2);
    }
};