import {Degree} from "./degree"

export default class Student {
    private id: string
    private First_Name: string
    private Last_Name: string
    private Email: string
    private Age: number
    private Student_Degree: Degree
    private CourseDays: Array<Number>

    constructor(id:string, firstname:string, lastname:string, email:string, age:number, degree:Degree, coursedays:Array<Number>) {
        this.id = id
        this.First_Name = firstname
        this.Last_Name = lastname
        this.Email = email
        this.Age = age
        this.Student_Degree = degree
        this.CourseDays = coursedays
    }

    getID():string {return this.id}
    getFirstName():string {return this.First_Name}
    getLastName():string {return this.Last_Name}
    getEmail():string {return this.Email}
    getAge():Number {return this.Age}
    getDegree():Degree {return this.Student_Degree}
    getCourseDays():Array<Number> {return this.CourseDays}

    setID(id:string):void {this.id = id}
    setFirstName(name:string):void {this.First_Name = name}
    setLastName(name:string):void {this.Last_Name = name}
    setEmail(email:string):void {this.Email = email}
    setAge(age:number):void {this.Age = age}
    setDegree(degree: Degree):void {this.Student_Degree = degree}
    setCourseDays(days:Array<Number>):void {this.CourseDays = days}


    Print():void {
        console.log(`${this.getID()}    ${this.getFirstName()}    ${this.getLastName()}    ${this.getEmail()}    ${this.getEmail()}    ${this.getAge()}    ${this.getDegree()}    ${this.getCourseDays()}`)
    }
}