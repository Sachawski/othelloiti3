/**
 * \file TADposition.h
 * \brief Implementation du TAD Position
 * \author P. Thulliez
 * \version 1.0
 * \date 06/12/2022
*/

#ifndef  __TADPOSITION__
#define __TADPOSITION__

/**
 * \struct POS_Position
 * \brief Modélise une position sur le plateau
 * POS_Position est un type qui permet de modéliser ce qu'est une position sur un plateau
*/
typedef struct {
    int x ; /**< Représente la colonne x*/     
    int y ; /**< Représente la ligne y */
} POS_Position ;

/**
* \fn POS_Position POS_position(int largeur, int hauteur )
* \brief Fonction qui retourne une position sachant la colonne et la ligne
* \param largeur Colonne de la position voulu
* \param hauteur Hauteur de la position voulu
* \return POS_Position (Position voulu)
*/
POS_Position POS_position(int largeur, int hauteur );

/**
* \fn int POS_obtenirX(POS_Position unePosition)
* \brief Fonction qui retourne l'entier correspondant à la la colonne à partir d'une position
* \param pos Position dont on souhaite connaitre la colonne
* \return int (Ligne de la position donnée)
*/
int POS_obtenirX(POS_Position pos);

/**
* \fn int POS_obtenirY(POS_Position unePosition)
* \brief Fonction qui retourne l'entier correspondant à la ligne à partir d'une position
* \param pos Position dont on souhaite connaitre la ligne
* \return int (Colonne de la position donnée)
*/
int POS_obtenirY(POS_Position pos);

#endif