#include <stdlib.h>
#include <ctime>
#include <conio.h>

class CAbase
{
public:
  CAbase()
    : Ny(10)
    , Nx(10)
    , Um(0)
    , nochanges(false)
  {
      ResetWorldSize( Nx , Ny, 1 );
  }
  CAbase( int nx, int ny, int um )
    : Ny(ny)
    , Nx(nx)
    , Um(um)
    , nochanges(false)
  {
      ResetWorldSize( Nx , Ny, 1 );
  }

  void ResetWorldSize( int nx, int ny, bool del = 0 );
  int Um;
  bool vertikal;
  bool horizontal;
  int GetNy() { return Ny; }
  int GetNx() { return Nx; }
  int GetColor(int x, int y) { return worldColor[y*(Nx+2)+x]; }
  void SetColor( int x, int y, int c);
  void SetColorEvo( int x, int y, int c);
  int GetLife(int x, int y) { return worldLife[y*(Nx+2)+x]; }
  void WorldEvolutionLife();
  void SetLife( int x, int y, int l);
  void SetLifeEvo( int x, int y, int l);
  void SetAlive( int x, int y, int i);
  void SetAliveEvo( int x, int y, int i);
  void SetUm(int x);
  void SetDircetion();
  void EatNahrung();
  void SpawnNahrung();
  int IsAlive( int x, int y ) { return world[y*(Nx+2)+x]; }
  bool IsNotChanged() { return nochanges; }
  int CellEvolutionLife( int x, int y);
  void SetStartpunkt(int x,int y, int startnahrung);
  void links();
  void rechts();
  void oben();
  void unten();
  bool gegessen;
  ~CAbase()
  {
  }
private:
  int Ny;
  int Nx;
  int Cx;
  int Cy;
  int *world;
  int *worldNew;
  int *worldColor;
  int *worldColorNew;
  int *worldLife;
  int *worldLifeNew;
  int nahrung;
  char key;
  bool nochanges;
  bool tot=false;

};
inline void CAbase::SetUm(int x)    //Setzt den UniversumMode
{
    Um = x;
}
inline void CAbase::SetAlive( int x, int y, int i) // Set number i into cell with coordinates x,y in current universe
{
  world[y*(Nx+2)+x] = i;
}

inline void CAbase::SetAliveEvo( int x, int y, int i) // Set number i into cell with coordinates x,y in evolution universe
{
  worldNew[y*(Nx+2)+x] = i;
}

inline void CAbase::SetColor( int x, int y, int c) //Set color c into cell with coordinates x,y in current color universe
{
    worldColor[y*(Nx+2)+x] = c;
}

inline void CAbase::SetColorEvo( int x, int y, int c) // Set color c into cell with coordinates x,y in evolution color universe
{
    worldColorNew[y*(Nx+2)+x] = c;
}

inline void CAbase::SetLife( int x, int y, int l) //Set lifetime l into cell with coordinates x,y in current color universe
{
    worldLife[y*(Nx+2)+x] = l;
}

inline void CAbase::SetLifeEvo( int x, int y, int l) // Set lifetime l into cell with coordinates x,y in evolution color universe
{
    worldLifeNew[y*(Nx+2)+x] = l;
}
//Steuerung der Schlange die über die Tastatur geändert werden kann (Hilfsfunktionen)
inline void CAbase::links()
{
    horizontal = false;
    vertikal = false;
}
inline void CAbase::rechts()
{
    horizontal = true;
    vertikal = false;
}
inline void CAbase::unten()
{
    horizontal = true;
    vertikal = true;
}
inline void CAbase::oben()
{
    horizontal = false;
    vertikal = true;
}


inline void CAbase::SpawnNahrung()      //Erschafft Nahrung irgendwo auf der Karte falls die Nahrung in einer lebendigen Zelle spawnt wird sie muss sie woanders spawnen
{
    int x;                              //zwei Random Zahlen, die die Koordinaten der Nahrung repräsentieren wenn die Zahlen zu Groß sind werden neue "gezogen"
    int y;
    do
    {
    x = rand();
    }
    while (x > Nx);
    do
    {
    y = rand();
    }
    while (y > Ny);
    if(IsAlive(x,y) < 1)
    {
        SetAlive(x,y, -5);        //Nahrung sollte einen Speziellen Wert haben der nicht abgezogen werden kann
    }
    else
    {
        SpawnNahrung();         //wenn kein passender Ort für die Nahrung gefunden wurde muss die Nahrung neu gesetzt werden
    }
}
inline void CAbase::EatNahrung()    //Wenn eine Nahrung gegessen wird
{
    gegessen = true;                //dient zur erweiterung der Schlange
    nahrung++;                      //hier wird die Schlange länger
    SpawnNahrung();                 //spawnt eine neue Nahrung nachdem die erste gegessen wurde
}

inline void CAbase::SetDircetion()                                       //Kopf der Schlange
{
    if(Cx >= Nx || Cy >= Ny || Cx <= 0 || Cy <= 0)                      //abfrage nach dem Rand
    {
        tot = true;

    }
    if(horizontal && vertikal)
    {
        //oben
        if (IsAlive(Cx,Cy+1) > 0)       //Kolisionsabfrage mit der Schlange
        {
         tot = true;
        }
        if (IsAlive(Cx,Cy+1) == -5)       //Kolisionsabfrage mit der Nahrung
        {
         EatNahrung();
        }
        SetAliveEvo(Cx,Cy+1, nahrung);  //setzt die Schlange ein Feld weiter
        Cy++;
    }
    if(!horizontal&& vertikal)
    {
        //unten
        if (IsAlive(Cx,Cy-1) > 0)
        {
         tot = true;
        }
        if (IsAlive(Cx,Cy-1) == -5)
        {
         EatNahrung();         
        }
        SetAliveEvo(Cx,Cy-1, nahrung);
        Cy--;
    }
    if(horizontal &&!vertikal)
    {
        //rechts
        if (IsAlive(Cx+1,Cy) > 0)
        {
         tot = true;
        }
        if (IsAlive(Cx+1,Cy) == -5)
        {
         EatNahrung();         
        }
        SetAliveEvo(Cx+1,Cy, nahrung);
        Cx++;
    }
    if(!horizontal &&!vertikal)
    {
        //links
        if (IsAlive(Cx-1,Cy) > 0)
        {
         tot = true;
        }
        if (IsAlive(Cx-1,Cy) == -5)
        {
         EatNahrung();         
        }
        SetAliveEvo(Cx-1,Cy, nahrung);
        Cx--;

    }
    SpawnNahrung();
}
inline void CAbase::SetStartpunkt(int x, int y, int startnahrung)       //Kopf der Schlange im Prinzip die PrepareFieldSnake() Funktion
{
    nahrung = startnahrung;
    vertikal = false;
    horizontal = false;
    tot = false;
    Cx = x;
    Cy = y;
    SpawnNahrung();
}
//
// Game "Life" rules: für Um!=1
//
// Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
// Any live cell with two or three live neighbours lives on to the next generation.
// Any live cell with more than three live neighbours dies, as if by overpopulation.
// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
//
//
inline int CAbase::CellEvolutionLife( int x, int y) // Classic Life. Evolution rules for every cell. Changing only cell (x, y) for every step
{   
    if (Um == 1)                //Snake Regeln
    {                           // ziehe jeder Lebenden Zelle 1 Leben ab. (Löscht das Feld wenn vorher CA ausgewählt wurde)
        if (IsAlive(x,y)== -5)  // Wenn die Zelle eine Nahrung ist dann mache nichts
        {
            SetAliveEvo(x,y, -5);

        }
        else
        {
        if (IsAlive(x,y)==0)    // Wenn die Zelle Tot ist dann mache nichts
            {
                SetAliveEvo(x,y,0);
            }
            else
            {
                if(gegessen)    // Wenn Die Zelle gegessen wurde dann wird die Zelle nicht decrementiert sondern angehängt
                {
                SetAliveEvo(x,y,IsAlive(x,y));                
                }
                else
                {
                    SetAliveEvo(x, y, IsAlive(x,y)-1);      //Decrementierung der Zelle, eine Zelle hat jetzt Leben, die Ablaufen um so ein bewegen zu simulieren.
                }
            }

        }

    }
    if (Um==0){
  int n_sum = 0;
  int x1(0), y1(0);
  for( int ix = -1; ix <= 1; ix++ ) {
    for( int iy = -1; iy <= 1; iy++ ) {
      if( ix == 0 && iy == 0 ) continue;
      x1 = x + ix;
      y1 = y + iy;
      if( x1 < 1 ) x1 = Nx;
      if( x1 > Nx ) x1 = 1;
      if( y1 < 1 ) y1 = Ny;
      if( y1 > Ny ) y1 = 1;
      if( IsAlive( x1, y1 ) == 1 ) n_sum++;
    }
  }
  if( IsAlive( x, y ) == 1 ) {
    if( n_sum == 2 || n_sum == 3 ) SetAliveEvo( x, y, 1 );
    else SetAliveEvo( x, y, 0 );
  }
  else {
    if( n_sum == 3 ) SetAliveEvo( x, y, 1  );
  }
    }
  return 0;
}


//
// Creation or re-creation new current and evolution universe with default value (0 for non-border cell and -1 for border cell)
//
//
inline void CAbase::ResetWorldSize( int nx, int ny, bool del )
{
  Nx = nx;
  Ny = ny;
  if( !del ) {
    delete[] world;
    delete[] worldNew;
    // Color
    delete[] worldColor;
    delete[] worldColorNew;
    // Life
    delete[] worldLife;
    delete[] worldLifeNew;
  }
  world = new int[(Ny+2)*(Nx+2)+1];
  worldNew = new int[(Ny+2)*(Nx+2)+1];
  // Color
  worldColor = new int[(Ny+2)*(Nx+2)+1];
  worldColorNew = new int[(Ny+2)*(Nx+2)+1];
  // Life
  worldLife = new int[(Ny+2)*(Nx+2)+1];
  worldLifeNew = new int[(Ny+2)*(Nx+2)+1];
  for( int i = 0; i <= (Ny+2)*(Nx+2); i++ ) {
    if( (i < (Nx+2)) || (i >= (Ny+1)*(Nx+2)) || (i%(Nx+2) == 0) || (i%(Nx+2) == (Nx+1)) ) {
	world[i] = -1;
	worldNew[i] = -1;
    // Color
    worldColor[i] = -1;
    worldColorNew[i] = -1;
    // Life
    worldLife[i] = -1;
    worldLifeNew[i] = -1;
    }
    else {
	world[i] = 0;
	worldNew[i] = 0;
    // Color
    worldColor[i] = 0;
    worldColorNew[i] = 0;
    // Life
    worldLife[i] = 0;
    worldLifeNew[i] = 0;
    }
  }
}

inline void CAbase::WorldEvolutionLife()
{
    for( int ix = 1; ix <= Nx; ix++ ) {                   // Universe evolution for every cell
        for( int iy = 1; iy <= Ny; iy++ ) {
                CellEvolutionLife( ix, iy );
        }
    }
    if(Um==1)
    {
    SetDircetion();     //updatet die Bewegung nach jedem durchlauf
    }    
    gegessen = false;
    nochanges = true;
      for( int ix = 1; ix <= Nx; ix++ ) {           // Copy new state to current universe
        for( int iy = 1; iy <= Ny; iy++ ) {
        if( world[iy*(Nx+2)+ix] != worldNew[iy*(Nx+2)+ix] ) nochanges = false;
        if(tot) nochanges = true;           //wenn die Schlange gegen die Wand fährt oder sich selbst beißt wird das Spiel beendet
        world[iy*(Nx+2)+ix] = worldNew[iy*(Nx+2)+ix];
        }
    }                                 // if nochanges == true, there are no evolution and we reached final stare of universe
}



