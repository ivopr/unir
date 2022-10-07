package src.window;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

import java.util.LinkedList;

import src.window.components.Field;
import src.elements.Person;
import src.elements.Student;

public class Window extends JFrame implements ActionListener, ItemListener {
  private static final long serialVersionUID = 1L;

  private ButtonGroup Group;
  private JButton Insert, ShowAll;
  private Field Name, Year, SID, T1, T2;
  private JPanel PersonPanel, StudentPanel;
  private JRadioButton RBPerson, RBStudent;
  private LinkedList<Person> List = new LinkedList<Person>();

  public Window() {
    super("Heritage: Person & Student - List");
    setLayout(new BorderLayout());
    Group = new ButtonGroup();
    RBPerson = new JRadioButton("Person", true);
    RBStudent = new JRadioButton("Student", false);
    Group.add(RBPerson);
    Group.add(RBStudent);

    JPanel North = new JPanel(new FlowLayout());
    North.add(RBPerson);
    North.add(RBStudent);
    add(North, BorderLayout.NORTH);
    RBPerson.addItemListener(this);
    RBStudent.addItemListener(this);

    Name = new Field("Name", 10);
    Year = new Field("Birth Year", 10);
    SID = new Field("Student ID", 10);
    T1 = new Field("Test 1", 10);
    T2 = new Field("Test 2", 10);

    PersonPanel = new JPanel();
    PersonPanel.setLayout(new BoxLayout(PersonPanel, BoxLayout.Y_AXIS));
    PersonPanel.add(Name);
    PersonPanel.add(Year);

    StudentPanel = new JPanel();
    StudentPanel.setLayout(new BoxLayout(StudentPanel, BoxLayout.Y_AXIS));
    StudentPanel.add(SID);
    StudentPanel.add(T1);
    StudentPanel.add(T2);
    StudentPanel.setVisible(false);

    JPanel CenterPanel = new JPanel();
    CenterPanel.setLayout(new BoxLayout(CenterPanel, BoxLayout.Y_AXIS));
    CenterPanel.add(PersonPanel);
    CenterPanel.add(StudentPanel);
    CenterPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

    add(CenterPanel, BorderLayout.CENTER);

    Insert = new JButton("Insert");
    ShowAll = new JButton("Show All");

    JPanel South = new JPanel(new FlowLayout());
    South.add(Insert);
    South.add(ShowAll);
    add(South, BorderLayout.SOUTH);

    Insert.addActionListener(this);
    ShowAll.addActionListener(this);
  }

  @Override
  public void itemStateChanged(ItemEvent e) {
    if (e.getSource() == RBPerson) {
      PersonPanel.setVisible(true);
      StudentPanel.setVisible(false);
    } else if (e.getSource() == RBStudent) {
      PersonPanel.setVisible(true);
      StudentPanel.setVisible(true);
    }
    this.pack();
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    if(e.getSource() == Insert) {
      double t1 = 0, t2 = 0;
      int year = 0;
      Student s;
      Person p;
      String name = Name.getValue();
      String y = Year.getValue();
      try {
        year = Integer.parseInt(y);
        if(RBStudent.isSelected()) {
          String ID = SID.getValue();
          String vT1 = T1.getValue();
          String vT2 = T2.getValue();
          try {
            t1 = Double.parseDouble(vT1);
            t2 = Double.parseDouble(vT2);
            
            s = new Student(name, year, ID, t1, t2);
            List.add(s);
          } catch (NumberFormatException err) {
            String errM = "Hey... Apparently you typed characters instead of numbers...\n\nStack trace:\n";
            JOptionPane.showMessageDialog(null, errM + err, "List Info", JOptionPane.PLAIN_MESSAGE);  
          }
        } else {
          p = new Person(name, year);
          List.add(p);
        }
      } catch (NumberFormatException err) {
        String errM = "Hey... Seems like the year you typed isn't an year at all...\n\nStack trace:\n";
        JOptionPane.showMessageDialog(null, errM + err, "List Info", JOptionPane.PLAIN_MESSAGE);
      }
      Name.resetValue();
      Year.resetValue();
      SID.resetValue();
      T1.resetValue();
      T2.resetValue();
    } else if(e.getSource() == ShowAll) {
      String s = "";
      for(Person p:List) {
        s += p.toString() + "\n-------------------------\n";
      }
      if(List.isEmpty())
        s = "No entries to show";
      JOptionPane.showMessageDialog(null, s, "List Info", JOptionPane.PLAIN_MESSAGE);
    }
  }

  public static void main(String[] args) {
    Window x = new Window();
    x.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    x.pack();
    x.setLocationRelativeTo(null);
    x.setVisible(true);
  }
}
