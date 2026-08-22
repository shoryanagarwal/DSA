class Solution {
public:
    bool checkDivisibility(int n) {


        int temp=n;
        int sum=0;
        int product=1;

        while(temp>0){
            int digit=temp%10;
            sum+=digit;
            product*=digit;
            temp=temp/10;



        }



        int total=sum+product;
        if(n%total==0){
            return true;
        }
        else{
            return false;
        }
        
    }
};