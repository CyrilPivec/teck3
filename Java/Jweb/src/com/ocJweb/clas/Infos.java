package com.ocJweb.clas;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class Infos {
	private Connection connexion;

    /**
     * Recupere les News dans la base de donnée.
     */
	public List<Nouvelles> recupererNouvelles(){
		List<Nouvelles> nouvelles = new ArrayList<Nouvelles>();
		Statement statement = null;
		ResultSet resultat = null;
		
		ConnectDatabase();
		
		try{
			statement = connexion.createStatement();
			resultat = statement.executeQuery("SELECT titre, description, auteur FROM news;");
			while (resultat.next()){
				String titre = resultat.getString("titre");
				String description = resultat.getString("description");
				String auteur = resultat.getString("auteur");
				
				Nouvelles nouvelle = new Nouvelles();
				nouvelle.setTitre(titre);
				nouvelle.setDescription(description);
				nouvelle.setAuteur(auteur);
				
				nouvelles.add(nouvelle);
			}
		} catch (SQLException e) {
		} finally {
			try {
				if (resultat != null)
					resultat.close();
	            if (statement != null)
	            	statement.close();
	            if (connexion != null)
	            	connexion.close();
	        } catch (SQLException ignore) {
	        }
		}
		return (nouvelles);
	}
	
    /**
     * Connexion à la base de donnée mysql.
     * 
     * @see Infos#recupererNouvelles().
     * @see Infos#ajouterNouvelle(Nouvelles). 
     */
	private void ConnectDatabase(){
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e) {
		}
		try {
			connexion = DriverManager.getConnection("jdbc:mysql://localhost:3306/javaee", "root", "toto42");
		} catch (SQLException e) {
			e.printStackTrace();
        }
	}
	
    /**
     * Ajoute des News à la base de donnée.
     */
	public void ajouterNouvelle(Nouvelles nouvelle){
		ConnectDatabase();
		
		try {
            PreparedStatement preparedStatement = connexion.prepareStatement("INSERT INTO news(titre, description, auteur) VALUES(?, ?, ?);");
            preparedStatement.setString(1, nouvelle.getTitre());
            preparedStatement.setString(2, nouvelle.getDescription());
            preparedStatement.setString(3, nouvelle.getAuteur());

            System.out.println(nouvelle.getTitre());
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
	}
}
