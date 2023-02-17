/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fxdemo;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import static java.util.Collections.list;
import java.util.ResourceBundle;
import java.util.Scanner;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javax.swing.JFileChooser;

/**
 *
 * @author asus
 */
public class FXMLDocumentController implements Initializable {
    public static String text;
    public static String directory;
    @FXML public Label title;
    @FXML public ListView<String> listView;
    @FXML public TableView<word> tableView = new TableView<>();
    @FXML public TableColumn<word,String> word = new TableColumn<>();
    @FXML public TableColumn<word,Integer> frequency = new TableColumn<>();
   
    @FXML
    private Label label;
    
    public static String[] finalWords;
    public static int[] finalCount;
    @FXML
    private void listViewButtonPressed() throws IOException {
        listView.getItems().clear();
        calculateWordFrequency();
        
        for(String gu:finalWords){System.out.println(gu+" ");} ///Debug
        
        for(int x=0;x<finalWords.length;x++)
        {   
            String temp="";
            if(finalWords[x]!=null){
             temp +=finalWords[x]+"   ( "+finalCount[x]+" )";
             
            listView.getItems().add(temp);
            }
        }   
    }
    
    @FXML private void tableViewButtonPressed() throws IOException {
        calculateWordFrequency(); 
        tableView.setItems(getlist());
    }
    
    @FXML  public void openButtonPressed() throws IOException {
        
        JFileChooser fc = new JFileChooser();
        fc.setCurrentDirectory(new java.io.File("C:\\Program Files"));
        fc.setDialogTitle("Choose A File");
        fc.setFileSelectionMode(JFileChooser.FILES_ONLY);
        fc.showOpenDialog(null);
        
        directory = fc.getSelectedFile().getAbsolutePath();
        title.setText("You have choosen : "+directory);
        text = "";
        Scanner file = new Scanner(new File(directory));
        file.useDelimiter("[^A-Za-z0-9]+");
        while (file.hasNext())
        {
            text +=file.next().trim()+" ";
        }
    }
    
    
    public ObservableList<word> getlist() { 
        ///This will get table Items
        calculateWordFrequency();
        ObservableList<word> finalList = FXCollections.observableArrayList();
        for(int x=0;x<finalWords.length;x++)
        {
             if(finalWords[x]!=null)
            finalList.add(new word(finalWords[x],finalCount[x]));
        }
        
        return finalList;
    }
    
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO 
        word.setCellValueFactory(new PropertyValueFactory< >("word"));
        frequency.setCellValueFactory(new PropertyValueFactory<>("frequency"));
        
      
    }
    
    public void calculateWordFrequency() {
        String[] words = text.split(" ");
        String[] foundWords = new String[words.length];
        int[] foundCount = new int[words.length];
        int foundIndex= 0;

        for (String aWord : words) {
            int j = 0;
            for (; j < foundIndex; j++) {
                if (foundWords[j].equalsIgnoreCase(aWord)) { //found
                    foundCount[j]++;
                    break;
                }
            }
            if (j == foundIndex) {
                foundWords[foundIndex] = aWord;
                foundCount[foundIndex] = 1;
                foundIndex++;
            }          
      }
        
        finalWords = new String[foundWords.length];  ///Assigning word and frequency to finalWords[] and finalcount[] 
        finalCount = new int[foundWords.length];
   
        for(int temp=0;temp<foundWords.length;temp++)     
        {
            finalWords[temp] = foundWords[temp];
        }
        for(int temp=0;temp<foundWords.length;temp++)
        {
            finalCount[temp] = foundCount[temp];
        }
     
    } ///calculateWordFrequency method ends here
    
} //Class End
