bool isPalindrome(int x) {
    int temp=0;
    if(x<0||(x%10==0&&x!=0)) return 0 ;
    else{
        while(x>temp){
            temp=temp*10+x%10;
            x/=10;
        }
    }
    return (x==temp||x==temp/10);
}