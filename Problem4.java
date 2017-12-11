/* Name: Christine Zhu
Email: zhuc18@brandeis.edu
Date: October 23rd, 2016
PA 4 Problem 4 - This program reads the month, day and year of a date and tells
you what day of the week that date, with the starting day as 1/1/1601 as a Monday.
Bugs: none */
import java.util.Scanner;
public class Problem4{
  public static void main(String[] args){
    System.out.println("Please enter the month of the date as an integer"); //prompt
    System.out.println("Example: January is 1, February is 2, etc");//prompt
    Scanner console = new Scanner (System.in);
    int month = console.nextInt();
    System.out.println("Please enter the day of the date"); //prompt
    int day = console.nextInt();
    System.out.println("Please enter the year of the date");//prompt
    int year = console.nextInt();
    date(month, day, year); //call date method
  }
  //date method will use the inputs, and tell you what day of the week that date is
  public static void date(int month, int day, int year){
    // calculate years in between date inputed and starting date
    //calculate years in between to find amount many leap years were in between.
    //usually there is a leap year every 4 years, with the exceptions of years that
    // are divisible by 4 and 100 and not by 400 (example 1700, 1800, 1900).
    //accounts for removed leap years
    int between = year - 1600;
    int leapyears = (between /4) - (between/100) + (between/400);
    int daysInYear = year * 365; //calulate how many days occured in year
    if (month == 1){ //if january this will happen
      //if the year inputted was not a skipped leap year this will happen
      if (leapyears>0 && leapyears%100 > 0 && year%4 ==0 ){
        leapyears = leapyears - 1;
      //if the year inputted was a skipped leap year, this will happen.
      } else {
        leapyears = leapyears;
      }
      daysInYear = daysInYear + day + (leapyears); //total amount of days that occured up to the date
      String nom = nameOfDay(daysInYear); // call method nameOfDay to get the name of the day
      System.out.println("For the date " + month+"/"+ day + "/" +year+ ", the day is " + nom);
    }else if (month == 2){ //if february this will happen
      //if the year was not a skipped leap year, we need to remove the extra day from
      //the one leap year that hasn't occured yet cuz the extra day is feb 29th
      if (leapyears > 0 && day<= 29 && leapyears%100 > 0 && year%4 == 0){
        leapyears = leapyears - 1;
      //if it was a skipped leap year (1700, 1800 etc) no need to remove anything
      } else {
        leapyears = leapyears;
      }
      daysInYear = daysInYear + 31 + day +leapyears; //31 added since 31 days in January
      String nom = nameOfDay(daysInYear); // call method nameOfDay to get the name of the day
      System.out.println("For the date " + month+"/"+ day + "/" +year+ ", the day is " + nom);
    }else if (month == 3){ //for march
      daysInYear = daysInYear + 59 + day +leapyears; //59 added because sum of days in previous months
      String nom = nameOfDay(daysInYear); // call method nameOfDay to get the name of the day
      System.out.println("For the date " + month+"/"+ day + "/" +year+ ", the day is " + nom);
    }else if (month == 4){
      daysInYear = daysInYear + 90 + day+leapyears; //90 added because sum of days in previous months
      String nom = nameOfDay(daysInYear); // call method nameOfDay to get the name of the day
      System.out.println("For the date " + month+"/"+ day + "/" +year+ ", the day is " + nom);
    }else if (month == 5){
      daysInYear = daysInYear + 120 + day+leapyears; //120 added because sum of days in previous months
      String nom = nameOfDay(daysInYear); // call method nameOfDay to get the name of the day
      System.out.println("For the date " + month+"/"+ day + "/" +year+ ", the day is " + nom);
    }else if (month == 6){
      daysInYear = daysInYear + 151 + day +leapyears; //151 added because sum of days in previous months
      String nom = nameOfDay(daysInYear); // call method nameOfDay to get the name of the day
      System.out.println("For the date " + month+"/"+ day + "/" +year+ ", the day is " + nom);
    }else if (month == 7){
      daysInYear = daysInYear + 181 + day +leapyears; //181 added because sum of days in previous months
      String nom = nameOfDay(daysInYear); // call method nameOfDay to get the name of the day
      System.out.println("For the date " + month+"/"+ day + "/" +year+ ", the day is " + nom);
    }else if (month == 8){
      daysInYear = daysInYear + 212 + day +leapyears; //212 added because sum of days in previous months
      String nom = nameOfDay(daysInYear); // call method nameOfDay to get the name of the day
      System.out.println("For the date " + month+"/"+ day + "/" +year+ ", the day is " + nom);
    }else if (month == 9){
      daysInYear = daysInYear + 243 + day +leapyears; //243 added because sum of days in previous months
      String nom = nameOfDay(daysInYear); // call method nameOfDay to get the name of the day
      System.out.println("For the date " + month+"/"+ day + "/" +year+ ", the day is " + nom);
    }else if (month == 10){
      daysInYear = daysInYear + 273 + day+leapyears; //273 added because sum of days in previous months
      String nom = nameOfDay(daysInYear); // call method nameOfDay to get the name of the day
      System.out.println("For the date " + month+"/"+ day + "/" +year+ ", the day is " + nom);
    }else if (month == 11){
      daysInYear = daysInYear + 304 + day+ leapyears;
      String nom = nameOfDay(daysInYear); // call method nameOfDay to get the name of the day
      System.out.println("For the date " + month+"/"+ day + "/" +year+ ", the day is " + nom);
    }else {
      daysInYear = daysInYear + 334 + day +leapyears;
      String nom = nameOfDay(daysInYear); // call method nameOfDay to get the name of the day
      System.out.println("For the date " + month+"/"+ day + "/" +year+ ", the day is " + nom);
    }
  }
  //nameofDay mathod modulus the number of today days. The remainders are constant
  //and correspond to the same day of week. 
  public static String nameOfDay(int daysinyear){
    int daynumber = daysinyear % 7;
    if (daynumber == 0){
      String name = "Tuesday";
      return name;
    } else if (daynumber == 1){
      String name = "Wednesday";
      return name;
    } else if (daynumber == 2){
      String name = "Thursday";
      return name;
    } else if (daynumber == 3){
      String name = "Friday";
      return name;
    } else if (daynumber == 4){
      String name = "Saturday";
      return name;
    } else if (daynumber == 5){
      String name = "Sunday";
      return name;
    } else {
      String name = "Monday";
      return name;
    }
  }
}
