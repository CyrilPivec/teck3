package com.ocJweb.clas;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import com.ocJweb.servlets.Produit;

public class Commentaire {
	private Connection connexion;
    
	/**
     * Se connecte à la base de donnée mysql.
     * 
     * @see Commentaire#ajouterCommentaire(Coms)
     * @see Commentaire#recupererCommentaire()
     */
	private void chargDatabase(){
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
     * Ajoute un commentaire à la base de donnée.
     */
	public void ajouterCommentaire(Coms coms){
		chargDatabase();
		
		try {
            PreparedStatement preparedStatement = connexion.prepareStatement("INSERT INTO coms(commentaire, auteur) VALUES(?, ?);");
            preparedStatement.setString(1, coms.getCommentaire());
            preparedStatement.setString(2, coms.getAuteur());
            
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
	}
	
    /**
     * Recupere tous les commentaires de la base de donnée.
     */
	public List<Coms> recupererCommentaire(){
		List<Coms> coms = new ArrayList<Coms>();
		Statement statement = null;
		ResultSet resultat = null;
		
		chargDatabase();
		
		try {
            statement = connexion.createStatement();

            resultat = statement.executeQuery("SELECT commentaire, auteur FROM coms;");

            while (resultat.next()) {
                String comment = resultat.getString("commentaire");
                String auteur = resultat.getString("auteur");
		
                Coms commentaire  = new Coms();
                commentaire.setCommentaire(comment);
                commentaire.setAuteur(auteur);
                
                coms.add(commentaire);
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
        
        return coms;
	}
}
