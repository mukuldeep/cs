package your.package.name.utils;
import java.util.LinkedList;

public class LRU{
    LinkedList<String> linkedList;
    int size;
    public LRU(int size){
        linkedList = new LinkedList<>();
        this.size=size;
    }

    public void insert(String str){
        linkedList.remove(str);
        if(linkedList.size()>=size){
            linkedList.remove(linkedList.size()-1);
        }
        linkedList.add(0,str);

    }

    public String getAllItemsExceptCurr(String curr){
        String str="";
        for (String st : linkedList){
            if(st != curr){
                str+=st+",";
            }
        }
        if(str.length()!=0)
        {
            str=str.substring(0,str.length()-1);
        }
        System.out.println("all items: "+str);
        return str;
    }

    public void print(){
        for (String str : linkedList) {
            System.out.println(str);
        }
    }
}