class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
         int n= knowledge.size();
      HashMap<String,String>mp=new HashMap<>();
       for(int i=0;i<n;i++){
             mp.put(knowledge.get(i).get(0),knowledge.get(i).get(1));
       }   
       boolean check=false;
       int np=s.length();
       String ans="";
        String sp="";
       for(int i=0;i<np;i++){
          
        if(s.charAt(i)!='(' && s.charAt(i)!=')' && check==false){
             ans+=s.charAt(i);
        }else if(s.charAt(i)=='('){
            sp="";
            check=true;
        }else if(s.charAt(i)==')'){
           
            if(mp.containsKey(sp)){
              
                ans+=mp.get(sp);
            }else{
                ans+='?';
            }
            sp="";
            check=false;
        }else if(s.charAt(i)!='(' && s.charAt(i)!=')' && check==true){
            sp+=s.charAt(i);
        }
       }
       return ans;
    }
}