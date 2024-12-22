package com.kaseknife95;

public class Student {
    private String id;
    private String First_Name;
    private String  Last_Name;
    private String Email;
    private int Age;
    private Degree Student_Degree;
    private int[] CourseDays;

    public Student(String id, String First_Name, String Last_Name, String Email, int Age, Degree Student_Degree, int[] CourseDays) {
        this.setID(id);
        this.setFirstName(First_Name);
        this.setLastName(Last_Name);
        this.setEmail(Email);
        this.setAge(Age);
        this.setDegree(Student_Degree);
        this.setCourseDays(CourseDays);
    }

    public String getID() {
        return this.id;
    }
    public String getFirstName() {
        return this.First_Name;
    }
    public String getLastName() {
        return this.Last_Name;
    }
    public String getEmail() {
        return this.Email;
    }
    public int getAge() {
        return this.Age;
    }
    public Degree getDegree() {
        return this.Student_Degree;
    }
    public int[] getCourseDays() {
        return this.CourseDays;
    }

    public void setID(String id) {
         this.id = id;
    }
    public void setFirstName(String name) {
         this.First_Name = name;
    }
    public void setLastName(String name) {
         this.Last_Name  = name;
    }
    public void setEmail(String email) {
         this.Email = email;
    }
    public void setAge(int age) {
         this.Age = age;
    }
    public void setDegree(Degree degree) {
         this.Student_Degree = degree;
    }
    public void setCourseDays(int[] days) {
         this.CourseDays = days;
    }

    public void Print(){
        System.out.println(this.getID()+"   "+this.getFirstName()+"   "+this.getLastName()+"   "+this.getEmail()+"   "+this.getAge()+"   "+this.getDegree()+"   "+String.valueOf(this.getCourseDays()[0])+" "+String.valueOf(this.getCourseDays()[1])+" "+String.valueOf(this.getCourseDays()[2]));
    }
}
