import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BookingSystem extends JFrame implements ActionListener {

    JCheckBox checkBox;
    JTextField nameField;
    JTextField flightField;
    JComboBox<String> seatBox;
    JButton button;

    BookingSystem () {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Flight Booking System");
        this.setSize(450,300);

        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();

        gbc.insets = new Insets(8, 8, 8, 8); // spacing

        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.LINE_END;
        panel.add(new JLabel("Passenger Name: "),gbc);

        gbc.gridx = 1;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.LINE_START;
        nameField = new JTextField(15);
        panel.add(nameField,gbc);


        gbc.gridx = 0;
        gbc.gridy = 1;
        panel.add(new JLabel("Flight Number: "),gbc);

        gbc.gridx = 1;
        gbc.gridy = 1;
        gbc.anchor = GridBagConstraints.LINE_START;
        flightField = new JTextField(15);
        panel.add(flightField,gbc);

        gbc.gridx = 0;
        gbc.gridy = 2;
        panel.add(new JLabel("Seat Preference:"),gbc);

        gbc.gridx = 1;
        gbc.gridy = 2;
        gbc.anchor = GridBagConstraints.LINE_START;
        seatBox =
                new JComboBox<>(new String[]{"Window", "Aisle"});
        panel.add(seatBox, gbc);

        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.gridwidth = 2;
        gbc.anchor = GridBagConstraints.LINE_START;
        checkBox = new JCheckBox("I agree to baggage rules");
        panel.add(checkBox,gbc);

        gbc.gridy = 4;
        gbc.gridx = 0;
        gbc.gridwidth = 2;
        gbc.anchor = GridBagConstraints.CENTER;
        button = new JButton("Confirm Booking");
        panel.add(button,gbc);
        button.addActionListener(this);


        this.add(panel);
        this.setLocationRelativeTo(null);
        this.setVisible(true);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String name = nameField.getText().trim();
        String flightNum = flightField.getText().trim();
        String seat = (String) seatBox.getSelectedItem();
        boolean agree = checkBox.isSelected();

        if (!agree) {
            JOptionPane.showMessageDialog(this,"Accept all baggage rules","Agreed",JOptionPane.WARNING_MESSAGE);
            return;
        }

        if(e.getSource()==button) {
            FileHandling handling = new FileHandling(name,flightNum,seat);
            nameField.setText("");
            flightField.setText("");
            seatBox.setSelectedIndex(0);
            checkBox.setSelected(false);

        }
    }
}