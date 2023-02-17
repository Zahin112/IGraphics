/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fxdemo;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;

/**
 *
 * @author asus
 */
public class word {
    
    public SimpleStringProperty word;
    public SimpleIntegerProperty frequency;

    public word(String word,int frequency) {
        this.word = new SimpleStringProperty(word);
        this.frequency = new SimpleIntegerProperty(frequency);
    }

    
    public String getWord() {
        return word.get();
    }

 
    public int getFrequency() {
        return frequency.getValue();
    }

    
    
    
    
    
}
