int evaluateExpression(string s){
    int sum = 0;
    int times = 0;
    int product = 1;
    for(int i = 0; i < s.length(); ++i){
        int number = 0;
        while(s[i] == ' ')
            ++i;
        while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
            number = number * 10 + s[i] - '0';
            ++i;
        }
        while(i < s.length() && s[i] == ' '){
            ++i;
        }
        
        if(i == s.length()){
            if(times){
                return product * number + sum;
            }else{
                return sum + number;
            }
        }else{
            if(s[i] == '+'){
                if(times){
                    sum += product * number;
                }else{
                    sum += number;
                }
                times = 0;
                product = 1;
            }else{
                times = 1;
                product *= number;
            }
        }
    }
    return sum;
}
