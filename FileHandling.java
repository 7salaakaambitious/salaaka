import javax.swing.*;
import java.awt.*;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class FileHandling  {

    String name;
    String flightNum;
    String seat;

    FileHandling(String name,String flightNum,String seat) {

        String timestamp = LocalDateTime.now()
                .format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));
        String record = "-----------------------------\n"
                + "Booking Time  : " + timestamp + "\n"
                + "Passenger Name: " + name     + "\n"
                + "Flight Number : " + flightNum   + "\n"
                + "Seat Preference: " + seat    + "\n"
                + "Baggage Rules Accepted: Yes"  + "\n";


        String path = "/Users/shaktisherpa/shakti.txt";

        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(path));
            writer.write(record);


            writer.close();
        } catch (java.io.IOException e) {
            JOptionPane.showMessageDialog(null,
                    "Error saving booking: " + e.getMessage(), "File Error",
                    JOptionPane.ERROR_MESSAGE);

        }
    }

}