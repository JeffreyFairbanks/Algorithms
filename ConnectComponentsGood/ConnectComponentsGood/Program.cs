using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.IO;
using Newtonsoft.Json;


namespace ConnectComponentsGood
{
  static class Program
  {
    /// <summary>
    /// The main entry point for the application.
    /// </summary>
    [STAThread]
    public static void Main(String[] args)
    {
      try
      {
        if (args.Length > 0)
        {
          string filename = args[0];

          StreamReader reader = new StreamReader(filename);
          string json = reader.ReadToEnd();
          reader.Close();

          var constraints = JsonConvert.DeserializeObject<Root>(json);

          var dict = new Dictionary<int, string>();

          for(int i = 0; i < constraints.CountyNames.Count; i++)
          {
            dict.Add(i, constraints.CountyNames[i]);
          }

          int vertices = constraints.CountyNames.Count;
          var edges = constraints.FindEdges();
          int edgeCount = edges.Count;

          Graph graph = new Graph(vertices, edgeCount, dict);

          for(int i = 0; i < edgeCount; i++)                        //populate the edges of the graph 
          {
            graph.edge[i].src = edges[i].Key;
            graph.edge[i].dest = edges[i].Value;
            graph.edge[i].weight = 1;
          }                                                          //building the graph


          // Function call
          graph.KruskalMST();
        }

      } 
      catch
      {
        Console.WriteLine("error message :( \n");
      }
      Console.ReadLine();
    }
  }
}








