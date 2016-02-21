package com.ocJweb.clas;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class User {
	private Connection connexion;
	
    /**
     * Recupere la liste des Utilisateur dans la base de donnée. 
     */
	public List<Utilisateur> recupererUtilisateur() {
		List<Utilisateur> utilisateurs = new ArrayList<Utilisateur>();
		Statement statement = null;
		ResultSet resultat = null;
		
		loadDatabase();
		
		try {
            statement = connexion.createStatement();

            resultat = statement.executeQuery("SELECT nom, prenom, mdp, mail, newsletter, admin FROM user;");

            while (resultat.next()) {
                String nom = resultat.getString("nom");
                String prenom = resultat.getString("prenom");
                String mdp = resultat.getString("mdp");
                String mail = resultat.getString("mail");
                Boolean newsLetter = resultat.getBoolean("newsletter");
                Boolean admin = resultat.getBoolean("admin");
                
                Utilisateur utilisateur = new Utilisateur();
                utilisateur.setNom(nom);
                utilisateur.setPrenom(prenom);
                utilisateur.setMdp(mdp);
                utilisateur.setMail(mail);
                utilisateur.setNewsLetter(newsLetter);
                utilisateur.setAdmin(admin);
                
                utilisateurs.add(utilisateur);
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
        
        return utilisateurs;
	}
	
    /**
     * Se connecte à la base de donnée.
     * 
     * @see User#ajouterUser(Utilisateur).
     * @see User#recupererUtilisateur(). 
     */
	private void loadDatabase(){
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
     * Ajoute l'utilisateur à la base donnée.
     */
	public void ajouterUser(Utilisateur utilisateur){
		loadDatabase();
		
		try {
            PreparedStatement preparedStatement = connexion.prepareStatement("INSERT INTO user(nom, prenom, mdp, mail, newsLetter, admin) VALUES(?, ?, ?, ?, ?, ?);");
            preparedStatement.setString(1, utilisateur.getNom());
            preparedStatement.setString(2, utilisateur.getPrenom());
            preparedStatement.setString(3, utilisateur.getMdp());
            preparedStatement.setString(4, utilisateur.getMail());
            preparedStatement.setBoolean(5, utilisateur.isNewsLetter());
            preparedStatement.setBoolean(6, utilisateur.isAdmin());
            
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
	}
	
    /**
     * Retour l'utilisateur demandé. 
     */
	public Utilisateur getUser(String mail, String mdp){
		String sql = "SELECT * FROM user WHERE mail = '" + mail + "' AND mdp = '" + mdp + "';";
		System.out.println(sql);
		Statement statement = null;
		ResultSet resultat = null;
		
		loadDatabase();
		try {
			statement = connexion.createStatement();
            resultat = statement.executeQuery(sql);
            System.out.println(sql);
            while (resultat.next()) {
            	if (resultat.getString("mail").equals(mail) && resultat.getString("mdp").equals(mdp))
            	{
            		Utilisateur utilisateur = new Utilisateur();
                    utilisateur.setNom(resultat.getString("nom"));
                    utilisateur.setPrenom(resultat.getString("prenom"));
                    utilisateur.setMdp(resultat.getString("mdp"));
                    utilisateur.setMail(resultat.getString("mail"));
                    utilisateur.setNewsLetter(resultat.getBoolean("newsletter"));
                    utilisateur.setAdmin(resultat.getBoolean("admin"));
                    
                    return (utilisateur);
            	}
            }
		}
		catch (SQLException e){
			e.printStackTrace();
		}
		return (null);
	}
}
