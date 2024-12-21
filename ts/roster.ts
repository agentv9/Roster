import { Degree } from './degree';

import Student from './student';
export default class Roster {

    studentRoster: Array<Student> = []

    totalStudents: number = 0
    nextid: number = 0

    parseString(data:string): void {
        let array = data.split(',')
        let degree:Degree

        if(array[8] == "SECURITY"){
            degree = Degree.SECURITY
        }else if(array[8] == "NETWORK"){
            degree = Degree.NETWORK
        }else {
            degree = Degree.SOFTWARE
        }

        this.addStudent(array[0], array[1], array[2], array[3], Number(array[4]), [Number(array[5]), Number(array[6]), Number(array[7])], degree)
        return
    }
    addStudent( id:string,  firstName:string,  lastName:string,  emailAddress:string,  age:number, coursedays:Array<number>,  degreeprogram:Degree):void {
        let student = new Student(id, firstName, lastName, emailAddress, age, degreeprogram, coursedays)
        this.studentRoster.push(student)
        return
    }
    removeStudent(id:string):void {
        let located:boolean = false
        for (let i = 0; i < this.studentRoster.length; i++){
            if(this.studentRoster[i].getID() == id) {
                this.studentRoster.splice(i, 1)
                located = true
            }
        }
        if (located == false) {
           console.log("The student with the ID: " + id + " was not found.")
        }
        return;
    }
    printAllStudents():void {
        for (const student of this.studentRoster) {
            student.Print()
        }
    }
    printAverageDaysInCourse(id: string):void {
        let totalDays:number = 0
        let averageDays

        for(let i = 0; i < this.studentRoster.length; i++) {
            if(this.studentRoster[i].getID() == id){
                for(const day of this.studentRoster[i].getCourseDays()){
                    totalDays += day as any as number
                }
            }
        }
        averageDays = totalDays / 3;

        console.log("Student ID: " + id + ", Average days in course is: " + averageDays)
        return

    }
    printInvalidEmails():void {
        for(let i = 0; i < this.studentRoster.length; i++) {
           let email = this.studentRoster[i].getEmail()

           if(email.includes(" ") || !email.includes("@") || !email.includes(".")) {
            console.log(email + " - Is invalid.")
           }

        }
        return
    }
    printByDegreeProgram(degree: Degree):void {
        for(let i = 0; i < this.studentRoster.length; i++) {
            if(this.studentRoster[i].getDegree() == degree){
               this.studentRoster[i].Print()
            }
        }
        return
    }
}