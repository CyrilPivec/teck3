package com.ocJweb.servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.ocJweb.clas.Commentaire;
import com.ocJweb.clas.Coms;
import com.ocJweb.clas.Utilisateur;

/**
 * Servlet implementation class Produit
 */
@WebServlet("/Produit")
public class Produit extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Produit() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		Commentaire commentaire = new Commentaire();
		request.setAttribute("commentaires", commentaire.recupererCommentaire());
		this.getServletContext().getRequestDispatcher("/WEB-INF/produit.jsp").forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		Coms commentaire = new Coms();
		commentaire.setCommentaire(request.getParameter("commentaire"));
		
		HttpSession session = request.getSession();
		Utilisateur utilisateur = (Utilisateur) session.getAttribute("user");
		
		commentaire.setAuteur(utilisateur.getPrenom());
		
		System.out.println(commentaire.getAuteur());
		
		Commentaire coms = new Commentaire();
		coms.ajouterCommentaire(commentaire);
		
		this.getServletContext().getRequestDispatcher("/WEB-INF/produit.jsp").forward(request, response);
	}

}
