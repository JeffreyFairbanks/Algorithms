using System;
using System.Collections.Generic;
using System.Text;

namespace ConnectComponentsGood
{
  public class Root
  {
    // Root myDeserializedClass = JsonConvert.DeserializeObject<Root>(myJsonResponse); 
    public List<string> CountyNames { get; set; }
    public List<string> Domain { get; set; }
    public List<List<int>> Graph { get; set; }


  public List<KeyValuePair<int, int>> FindEdges()
  {

      var edges = new List<KeyValuePair<int, int>>();

      for(int i = 0; i < Graph.Count; i++)
      {
        for(int j = 0; j < Graph[i].Count; j++)
        {
          if(Graph[i][j] == 1)
          {
            var pair = new KeyValuePair<int, int>(i, j);
            var pair2 = new KeyValuePair<int, int>(j, i);

            if (!edges.Contains(pair) && !edges.Contains(pair2)) //check if edge has been accounted for
              edges.Add(pair);

          }
        }
      }

      return edges;
  }

  }

}
