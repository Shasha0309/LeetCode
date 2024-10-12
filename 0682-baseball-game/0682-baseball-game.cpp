class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> rec;
        int sum = 0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                 if(rec.size()>=2){
                    int lastone = rec[rec.size()-1];
                    int lasttwo = rec[rec.size()-2];
                    rec.push_back(lastone+lasttwo);
                 }
            }
            else if(operations[i]=="D"){
                if(!rec.empty()){
                rec.push_back(rec.back()*2);
                }
            }
            else if(operations[i]=="C"){
                if(!rec.empty()){
                rec.pop_back();
                }
            }
            else{
                int num = stoi(operations[i]);
                rec.push_back(num);
            }
        }
        for(int nu:rec){
            sum+=nu;
        }
        return sum; 
    }
};