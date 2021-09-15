// Clase Concreta
abstract class Human{
    public void eat(){
        System.out.println("El humano come.");
    }
    public abstract void toLive();
}

class Student extends Human{
    protected int identifier;
    protected String name;
    protected String surname;
    
    public Student(int id, String n, String s){
        this.identifier = id;
        this.name = n;
        this.surname = s;
    }
    
    public void setIdentifier(int id){
        this.identifier = id;
    }
    
    public void setName(String name){
        this.name = name;
    }
    
    public void setSurname(String surname){
        this.surname = surname;
    }
    
    public int getIdentifier(){
        return this.identifier;
    }
    
    public String getName(){
        return this.name;
    }
    
    public String getSurname(){
        return this.surname;
    }
    
    /*
    public void eat(){
        System.out.println("El estudiante " + this.name + " " + this.surname + " no puede comer en clase.");
    }
    */
    public void toLive(){
        System.out.println("El estudiante " + this.name + " " + this.surname + " vive.");
    }
}

class Main{
    public static void main(String[] args) {

        Student student = new Student(75, "Agustin", "Souto");
    
        student.eat();
        student.toLive();
    }
}