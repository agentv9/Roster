<?php
require(__DIR__ ."/Degree.php");
class Student {
    private string $id;
    private string $First_Name;
    private string $Last_Name;
    private string $Email;
    private int $Age;
    private Degree $Student_Degree;
    private array $CourseDays;

    function __construct(string $id, string $firstname,string $lastname,string $email,int $age,Degree $degree,array $coursedays){
        $this->setID($id);
        $this->setFirstName($firstname);
        $this->setLastName($lastname);
        $this->setEmail($email);
        $this->setAge($age);
        $this->setDegree($degree);
        $this->setCourseDays($coursedays);
    }

    function getID() {return $this->id;}
    function getFirstName() {return $this->First_Name;}
    function getLastName() {return $this->Last_Name;}
    function getEmail() {return $this->Email;}
    function getAge() {return $this->Age;}
    function getDegree() {return $this->Student_Degree;}
    function getCourseDays() {return $this->CourseDays;}

    function setID($id) {return $this->id = $id;}
    function setFirstName($name) {return $this->First_Name = $name;}
    function setLastName($name) {return $this->Last_Name = $name;}
    function setEmail($email) {return $this->Email = $email;}
    function setAge($age) {return $this->Age = $age;}
    function setDegree($degree) {return $this->Student_Degree = $degree;}
    function setCourseDays($days) {return $this->CourseDays = $days;}

    function Print() {
        print( $this->getID(). "  ". $this->getFirstName(). "  ".    $this->getLastName(). "  ".    $this->getEmail(). "  ".      $this->getAge(). "  ". $this->getDegree()->name. "  ".      implode( " ", $this->getCourseDays()) ."\n"); 
    }
}
