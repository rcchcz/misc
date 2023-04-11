package Keno;

public class IOError extends Exception{
    public String getMessage(){
        return "Game closed due to invalid operation.";
    }
}