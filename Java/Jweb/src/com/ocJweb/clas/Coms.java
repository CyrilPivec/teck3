package com.ocJweb.clas;

public class Coms {
	private String commentaire;
	private String auteur;
	
    /**
     * Retourne le commentaire.
     * 
     * @return Le commentaire. 
     */
	public String getCommentaire() {
		return commentaire;
	}
	
    /**
     * Initialise le commentaire. 
     */
	public void setCommentaire(String commentaire) {
		this.commentaire = commentaire;
	}
	
    /**
     * Retourne le nom de l'auteur du commentaire.
     * 
     * @return le nom de l'auteur du commentaire. 
     */
	public String getAuteur() {
		return auteur;
	}
	
    /**
     * Initialise l'auteur du commentaire. 
     */
	public void setAuteur(String auteur) {
		this.auteur = auteur;
	}
}
