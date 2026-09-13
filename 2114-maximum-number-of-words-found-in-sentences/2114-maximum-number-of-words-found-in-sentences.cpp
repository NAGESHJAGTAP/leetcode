class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int size=sentences.size();
        int count=0;
        for(int i=0; i<size; i++){
            int word=1;
       for(int j=0; j <sentences[i].size(); j++){
        if(sentences[i][j] == ' '){
            word++;
        }
        count= max(count , word);
       }
        }
        return count;
        
    }
};