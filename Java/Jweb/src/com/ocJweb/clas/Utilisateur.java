package com.ocJweb.clas;

public class Utilisateur {
	private String nom;
	private String prenom;
	private String mdp;
	private String mail;
	private boolean newsLetter;
	private boolean admin;
	
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	
	public String getPrenom() {
		return prenom;
	}
	public void setPrenom(String prenom) {
		this.prenom = prenom;
	}
	
	public String getMdp() {
		return mdp;
	}
	public void setMdp(String mdp) {
		this.mdp = mdp;
	}
	
	public String getMail() {
		return mail;
	}
	public void setMail(String mail) {
		this.mail = mail;
	}
	
	public boolean isNewsLetter() {
		return newsLetter;
	}
	public void setNewsLetter(boolean newsLetter) {
		this.newsLetter = newsLetter;
	}
	
	public boolean isAdmin() {
		return admin;
	}
	public void setAdmin(boolean admin) {
		this.admin = admin;
	}
}
