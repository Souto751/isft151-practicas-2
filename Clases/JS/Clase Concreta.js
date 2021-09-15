// Clase Concreta;
class Human {
    constructor(){}
    eat(){
        console.log("El humano come.");
    }
    
    toLive(){
        console.log("El humano vive.");
    };
};

class Student extends Human {
    constructor(id, name, surname){
        super();
        this.identifier = id;
        this.name = name;
        this.surname = surname;
    }
    
    setIdentifier(id){
        this.identifier = id;
    }
    
    setName(name){
        this.name = name;
    }
    
    setSurname(surname){
        this.surname = surname;
    }
    
    getIdentifier(){
        return this.identifier;
    }
    
    getName(){
        return this.name;
    }
    
    getSurname(){
        return this.surname;
    }
    
    eat(){
        console.log("El estudiante " + this.name + " " + this.surname + " no puede comer en clase.");
    }
    
    /*
    toLive(){
        console.log("El estudiante " + this.name + " " + this.surname + " vive.");
    }
    */
};


let student = new Student(75, "Agustin", "Souto");
student.eat();
student.toLive();