using System;
using System.Collections.Generic;
using System.Text;

namespace ConnectComponentsGood
{
  public class Root  //used to parse the JSON files
  {
    // Root myDeserializedClass = JsonConvert.DeserializeObject<Root>(myJsonResponse); 

    //getters and setters for the values that will be seen in the Json
    public List<string> CountyNames { get; set; }
    public List<string> Domain { get; set; }
    public List<List<int>> Graph { get; set; }


    public List<KeyValuePair<int, int>> FindEdges()   //function of the Root class to find the edges of the graph that was passed in
    {

        var edges = new List<KeyValuePair<int, int>>();   //used to look at a pair and decide if it is an edge

        for(int i = 0; i < Graph.Count; i++)  //going through the graph 
        {
          for(int j = 0; j < Graph[i].Count; j++)
          {
            if(Graph[i][j] == 1)   //if it finds a 1, then it is an edge and we must inspect further
            {
              var pair = new KeyValuePair<int, int>(i, j);            //checks for a 0, 1 pair 
              var pair2 = new KeyValuePair<int, int>(j, i);           //checks for a 1, 0 pair

              if (!edges.Contains(pair) && !edges.Contains(pair2)) //check if edge has been accounted for already
                edges.Add(pair);  //if it hasnt, add the pair as an edge of the graph 

            }
          }
        }
        return edges;  //after all this is done, the function will return all the edges
    }
  }
}
