#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

vector<pair<int, float>> g[235];
map<int, string> mpr;
map<string, int> mp;

void addEdge(vector<vector<int>> &graph,
             int u, int v, float dist, int dist2, bool bidir = true)
{
    // distance
    g[u].push_back(make_pair(v, dist));
    if (bidir)
        g[v].push_back(make_pair(u, dist));
    // max flow
    graph[u][v] = dist2;
    graph[v][u] = dist2;
}

typedef pair<int, int> iPair;
vector<int> path;
void printPath(vector<int> const &prev, int i, int source)
{
    if (i < 0)
    {
        return;
    }
    printPath(prev, prev[i], source);
    if (i != source)
    {
        cout << ",\n";
    }

    path.push_back(mp[mpr[i]]);
    cout << mpr[i];
}

void shortestPath(vector<pair<int, float>> adj[], int V, int src, int deststn)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<float> dist(V, INF);

    vector<bool> visited(V, false);
    vector<int> prev(V, -1);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
        {
            continue;
        }
        visited[u] = true;

        for (auto x : adj[u])
        {
            int v = x.first;
            float weight = x.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                prev[v] = u;
            }
        }
    }

    int i = deststn;
    if (i != src && dist[i] != INT_MAX)
    {
        cout << "\nMinimum distance = "
             << dist[i] << " KM, \nRoute = \n[";
        printPath(prev, deststn, src);
        cout << "]" << endl;
    }
}

int bfs(int source, int sink, vector<int> &parent, vector<vector<int>> &residualGraph)
{
    fill(parent.begin(), parent.end(), -1);
    int V = residualGraph.size();
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});

    while (!q.empty())
    {
        int u = q.front().first;
        int capacity = q.front().second;
        q.pop();
        for (int av = 0; av < V; av++)
        {
            if (u != av && parent[av] == -1 && residualGraph[u][av] != 0)
            {
                parent[av] = u;
                int min_cap = min(capacity, residualGraph[u][av]);
                if (av == sink)
                    return min_cap;
                q.push({av, min_cap});
            }
        }
    }
    return 0;
}

int ford_fulkerson(vector<vector<int>> &graph, int source, int sink)
{
    vector<int> parent(graph.size(), -1);
    vector<vector<int>> residualGraph = graph;
    int min_cap = 0, max_flow = 0;
    while (min_cap = bfs(source, sink, parent, residualGraph))
    {
        max_flow += min_cap;
        int u = sink;
        while (u != source)
        {
            int v = parent[u];
            residualGraph[u][v] += min_cap;
            residualGraph[v][u] -= min_cap;
            u = v;
        }
    }
    return max_flow;
}

float fare()
{
    int f = 0;
    for (int a : path)
        f += 0.2 * a;
    return f;
}

int main()
{
    // Mapping stations names to numerical integers
    mp.insert({"Dilshad Garden", 1}); mpr.insert({1, "Dilshad Garden"});
    mp.insert({"Jhilmil", 2}); mpr.insert({2, "Jhilmil"});
    mp.insert({"Mansrovar park", 3}); mpr.insert({3, "Mansrovar park"});
    mp.insert({"Shahdara", 4});  mpr.insert({4, "Shahdara"});
    mp.insert({"Welcome", 5}); mpr.insert({5, "Welcome"});
    mp.insert({"Seelampur", 6});  mpr.insert({6, "Seelampur"});
    mp.insert({"Shastri Park", 7}); mpr.insert({7, "Shastri Park"});
    mp.insert({"Kashmere Gate", 8}); mpr.insert({8, "Kashmere Gate"});
    mp.insert({"Tis Hazari", 9}); mpr.insert({9, "Tis Hazari"});
    mp.insert({"Pulbangash", 10});  mpr.insert({10, "Pulbangash"});
    mp.insert({"Pratap Nagar", 11}); mpr.insert({11, "Pratap Nagar"});
    mp.insert({"Shastri Nagar", 12}); mpr.insert({12, "Shastri Nagar"});
    mp.insert({"Inderlok", 13}); mpr.insert({13, "Inderlok"});
    mp.insert({"Kanhaiya Nagar", 14}); mpr.insert({14, "Kanhaiya Nagar"});
    mp.insert({"Keshav Puram", 15}); mpr.insert({15, "Keshav Puram"});
    mp.insert({"Netaji Subhash Place", 16}); mpr.insert({16, "Netaji Subhash Place"});
    mp.insert({"Kohat Enclave", 17}); mpr.insert({17, "Kohat Enclave"});
    mp.insert({"Pitam Pura", 18}); mpr.insert({18, "Pitam Pura"});
    mp.insert({"Rohini East", 19}); mpr.insert({19, "Rohini East"});
    mp.insert({"Rohini West", 20}); mpr.insert({20,	"Rohini West"});
    mp.insert({"Rithala", 21}); mpr.insert({21,	"Rithala"});
    mp.insert({"Samaypur Badli", 22}); mpr.insert({22,	"Samaypur Badli"});
    mp.insert({"Rohini Sector - 18", 23}); mpr.insert({23,	"Rohini Sector - 18"});
    mp.insert({"Haiderpur Badli Mor", 24}); mpr.insert({24,	"Haiderpur Badli Mor"});
    mp.insert({"Jahangirpuri", 25}); mpr.insert({25,	"Jahangirpuri"});
    mp.insert({"Adarsh Nagar", 26}); mpr.insert({26,	"Adarsh Nagar"});
    mp.insert({"Azadpur", 27}); mpr.insert({27,	"Azadpur"});
    mp.insert({"Model Town", 28}); mpr.insert({28,	"Model Town"});
    mp.insert({"GTB Nagar", 29}); mpr.insert({29,	"GTB Nagar"});
    mp.insert({"Vishwavidyalaya", 30}); mpr.insert({30,	"Vishwavidyalaya"});
    mp.insert({"Vidhan Sabha", 31}); mpr.insert({31,	"Vidhan Sabha"});
    mp.insert({"Civil Lines", 32}); mpr.insert({32,	"Civil Lines"});
    mp.insert({"Kashmere Gate", 33}); mpr.insert({33,	"Kashmere Gate"});
    mp.insert({"Chandni Chowk", 34}); mpr.insert({34,	"Chandni Chowk"});
    mp.insert({"Chawri Bazar", 35}); mpr.insert({35,	"Chawri Bazar"});
    mp.insert({"New Delhi", 36}); mpr.insert({36,	"New Delhi"});
    mp.insert({"Rajiv Chowk", 37}); mpr.insert({37,	"Rajiv Chowk"});
    mp.insert({"Patel Chowk", 38}); mpr.insert({38,	"Patel Chowk"});
    mp.insert({"Central Secretariat", 39}); mpr.insert({39, "Central Secretariat"});
    mp.insert({"Udyog Bhawan", 40}); mpr.insert({40, "Udyog Bhawan"});
    mp.insert({"Lok Kalyan Marg", 41}); mpr.insert({41, "Lok Kalyan Marg"});
    mp.insert({"Jor Bagh", 42}); mpr.insert({42, "Jor Bagh"});
    mp.insert({"INA", 43}); mpr.insert({43, "INA"});
    mp.insert({"AIIMS", 44}); mpr.insert({44, "AIIMS"});
    mp.insert({"Green Park", 45}); mpr.insert({45, "Green Park"});
    mp.insert({"Hauz Khas", 46}); mpr.insert({46, "Hauz Khas"});
    mp.insert({"Malviya Nagar", 47}); mpr.insert({47, "Malviya Nagar"});
    mp.insert({"Saket", 48}); mpr.insert({48, "Saket"});
    mp.insert({"Qutab Minar", 49}); mpr.insert({49, "Qutab Minar"});
    mp.insert({"Chhattarpur", 50}); mpr.insert({50, "Chhattarpur"});
    mp.insert({"Sultanpur", 51});  mpr.insert({51, "Sultanpur"});
    mp.insert({"Ghitorni", 52});  mpr.insert({52, "Ghitorni"});
    mp.insert({"Arjan Garh", 53});  mpr.insert({53, "Arjan Garh"});
    mp.insert({"Guru Dronacharya", 54});  mpr.insert({54, "Guru Dronacharya"});
    mp.insert({"Sikandarpur", 55});  mpr.insert({55, "Sikandarpur"});
    mp.insert({"MG Road", 56});  mpr.insert({56, "MG Road"});
    mp.insert({"IFFCO Chowk", 57});  mpr.insert({57, "IFFCO Chowk"});
    mp.insert({"Huda City Centre", 58}); mpr.insert({58, "Huda City Centre"});
    mp.insert({"Noida City Centre", 59});  mpr.insert({59, "Noida City Centre"});
    mp.insert({"Golf Course", 60});  mpr.insert({60, "Golf Course"});
    mp.insert({"Botanical Garden", 61});  mpr.insert({61, "Botanical Garden"});
    mp.insert({"Noida Sector-18", 62});  mpr.insert({62, "Noida Sector-18"});
    mp.insert({"Noida Sector-16", 63});  mpr.insert({63, "Noida Sector-16"});
    mp.insert({"Noida Sector-15", 64});  mpr.insert({64, "Noida Sector-15"});
    mp.insert({"New Ashok Nagar", 65});  mpr.insert({65, "New Ashok Nagar"});
    mp.insert({"Mayur Vihar Extention", 66}); mpr.insert({66, "Mayur Vihar Extention"});
    mp.insert({"Mayur Vihar Phase-1", 67});  mpr.insert({67, "Mayur Vihar Phase-1"});
    mp.insert({"Akshardham", 68});  mpr.insert({68, "Akshardham"});
    mp.insert({"Yamuna Bank", 69});  mpr.insert({69, "Yamuna Bank"});
    mp.insert({"Inderprastha", 70});  mpr.insert({70, "Inderprastha"});
    mp.insert({"Pragati Maiden", 71});  mpr.insert({71, "Pragati Maiden"});
    mp.insert({"Mandi House", 72});  mpr.insert({72, "Mandi House"});
    mp.insert({"Barakhamba Road", 73});  mpr.insert({73, "Barakhamba Road"});
    mp.insert({"Rajiv Chowk", 74});  mpr.insert({74, "Rajiv Chowk"});
    mp.insert({"RK Ashram Marg", 75});  mpr.insert({75, "RK Ashram Marg"});
    mp.insert({"Jhandewalan", 76});  mpr.insert({76, "Jhandewalan"});
    mp.insert({"Karol Bagh", 77});  mpr.insert({77, "Karol Bagh"});
    mp.insert({"Rajender Place", 78});  mpr.insert({78, "Rajender Place"});
    mp.insert({"Patel Nagar", 79});  mpr.insert({79, "Patel Nagar"});
    mp.insert({"Shadipur", 80});  mpr.insert({80, "Shadipur"});
    mp.insert({"Kirti Nagar", 81});  mpr.insert({81, "Kirti Nagar"});
    mp.insert({"Moti Nagar", 82});  mpr.insert({82, "Moti Nagar"});
    mp.insert({"Ramesh Nagar", 83});  mpr.insert({83, "Ramesh Nagar"});
    mp.insert({"Rajouri Garden", 84});  mpr.insert({84, "Rajouri Garden"});
    mp.insert({"Tagore Garden", 85});  mpr.insert({85, "Tagore Garden"});
    mp.insert({"Subash Nagar", 86});  mpr.insert({86, "Subash Nagar"});
    mp.insert({"Tilak Nagar", 87});  mpr.insert({87, "Tilak Nagar"});
    mp.insert({"Janak Puri East", 88});  mpr.insert({88, "Janak Puri East"});
    mp.insert({"Janak Puri West", 89});  mpr.insert({89, "Janak Puri West"});
    mp.insert({"Uttam Nagar East", 90});  mpr.insert({90, "Uttam Nagar East"});
    mp.insert({"Uttam Nagar West", 91});  mpr.insert({91, "Uttam Nagar West"});
    mp.insert({"Nawada", 92});  mpr.insert({92, "Nawada"});
    mp.insert({"Dwaraka Mor", 93});  mpr.insert({93, "Dwaraka Mor"});
    mp.insert({"Dwarka", 94});  mpr.insert({94, "Dwarka"});
    mp.insert({"Dwarka Sector14", 95});  mpr.insert({95, "Dwarka Sector14"});
    mp.insert({"Dwarka Sector13", 96});  mpr.insert({96, "Dwarka Sector13"});
    mp.insert({"Dwarka Sector12", 97});  mpr.insert({97, "Dwarka Sector12"});
    mp.insert({"Dwarka Sector11", 98});  mpr.insert({98, "Dwarka Sector11"});
    mp.insert({"Dwarka Sector10", 99});  mpr.insert({99, "Dwarka Sector10"});
    mp.insert({"Dwarka Sector9", 100}); mpr.insert({100, "Dwarka Sector9"});
    mp.insert({"Dwarka Sector8", 101}); mpr.insert({101, "Dwarka Sector8"});
    mp.insert({"Dwarka Sector21", 102}); mpr.insert({102, "Dwarka Sector21"});
    mp.insert({"Vaishali", 103}); mpr.insert({103, "Vaishali"});
    mp.insert({"Kaushambi", 104}); mpr.insert({104, "Kaushambi"});
    mp.insert({"Anand Vihar", 105}); mpr.insert({105, "Anand Vihar"});
    mp.insert({"Karkar Duma", 106});  mpr.insert({106, "Karkar Duma"});
    mp.insert({"Preet Vihar", 107});  mpr.insert({107, "Preet Vihar"});
    mp.insert({"Nirman Vihar", 108});  mpr.insert({108, "Nirman Vihar"});
    mp.insert({"Laxmi Nagar", 109});  mpr.insert({109, "Laxmi Nagar"});
    mp.insert({"City Park", 110});  mpr.insert({110, "City Park"});
    mp.insert({"Bus Stand", 111});  mpr.insert({111, "Bus Stand"});
    mp.insert({"Modern Industrial Estate", 112});  mpr.insert({112, "Modern Industrial Estate"});
    mp.insert({"Tikri Border", 113});  mpr.insert({113, "Tikri Border"});
    mp.insert({"Tikri Kalan", 114});  mpr.insert({114, "Tikri Kalan"});
    mp.insert({"Ghevra Metro Station", 115});  mpr.insert({115, "Ghevra Metro Station"});
    mp.insert({"Mundka Industrial Area", 116});  mpr.insert({116, "Mundka Industrial Area"});
    mp.insert({"Mundka", 117});  mpr.insert({117, "Mundka"});
    mp.insert({"Rajdhani Park", 118});  mpr.insert({118, "Rajdhani Park"});
    mp.insert({"Nangloi Rly. Station", 119});  mpr.insert({119, "Nangloi Rly. Station"});
    mp.insert({"Nangloi", 120});  mpr.insert({120, "Nangloi"});
    mp.insert({"Surajmal Stadium", 121});  mpr.insert({121, "Surajmal Stadium"});
    mp.insert({"Udyog Nagar", 122});  mpr.insert({122, "Udyog Nagar"});
    mp.insert({"Peera Garhi", 123});  mpr.insert({123, "Peera Garhi"});
    mp.insert({"Paschim Vihar (West)", 124});  mpr.insert({124, "Paschim Vihar (West)"});
    mp.insert({"Paschim Vihar (East)", 125});  mpr.insert({125, "Paschim Vihar (East)"});
    mp.insert({"Madipur", 126});  mpr.insert({126, "Madipur"});
    mp.insert({"Shivaji Park", 127});  mpr.insert({127, "Shivaji Park"});
    mp.insert({"Punjabi Bagh", 128});  mpr.insert({128, "Punjabi Bagh"});
    mp.insert({"Ashok Park", 129});  mpr.insert({129, "Ashok Park"});
    mp.insert({"Inderlok", 130});  mpr.insert({130, "Inderlok"});
    mp.insert({"Sant Guru Ram Singh Marg", 131});  mpr.insert({131, "Sant Guru Ram Singh Marg"});
    mp.insert({"Kirti Nagar", 132});  mpr.insert({132, "Kirti Nagar"});
    mp.insert({"Kashmere Gate", 133});  mpr.insert({133, "Kashmere Gate"});
    mp.insert({"Lal Qila", 134});  mpr.insert({134, "Lal Qila"});
    mp.insert({"Jama Masjid", 135});  mpr.insert({135, "Jama Masjid"});
    mp.insert({"Delhi Gate", 136});  mpr.insert({136, "Delhi Gate"});
    mp.insert({"ITO", 137});  mpr.insert({137, "ITO"});
    mp.insert({"Mandi House", 138});  mpr.insert({138, "Mandi House"});
    mp.insert({"Janptah", 139});  mpr.insert({139, "Janptah"});
    mp.insert({"Central Secretariat", 140});  mpr.insert({140, "Central Secretariat"});
    mp.insert({"Khan Market", 141});  mpr.insert({141, "Khan Market"});
    mp.insert({"JL Nehru Stadium", 142});  mpr.insert({142, "JL Nehru Stadium" });
    mp.insert({"Jangpura", 143});  mpr.insert({143, "Jangpura"});
    mp.insert({"Lajpat Nagar", 144});  mpr.insert({144, "Lajpat Nagar" });
    mp.insert({"Moolchand", 145});  mpr.insert({145, "Moolchand"});
    mp.insert({"Kailash Colony", 146});  mpr.insert({146, "Kailash Colony"});
    mp.insert({"Nehru Place", 147});  mpr.insert({147, "Nehru Place" });
    mp.insert({"Kalkaji Mandir", 148});  mpr.insert({148, "Kalkaji Mandir"});
    mp.insert({"Govindpuri", 149});  mpr.insert({149, "Govindpuri"});
    mp.insert({"Okhla", 150});  mpr.insert({150, "Okhla"});
    mp.insert({"Jasola-Apollo", 151}); mpr.insert({151, "Jasola-Apollo"});
    mp.insert({"Sarita Vihar", 152}); mpr.insert({152, "Sarita Vihar"});
    mp.insert({"Mohan Estate", 153}); mpr.insert({153, "Mohan Estate"});
    mp.insert({"Tuglakabad", 154}); mpr.insert({154, "Tuglakabad"});
    mp.insert({"Badarpur", 155}); mpr.insert({155, "Badarpur"});
    mp.insert({"Sarai", 156}); mpr.insert({156, "Sarai"});
    mp.insert({"NHPC Chowk", 157}); mpr.insert({157, "NHPC Chowk"});
    mp.insert({"Mewala Maharajpur", 158}); mpr.insert({158, "Mewala Maharajpur"});
    mp.insert({"Sector-28", 159}); mpr.insert({159, "Sector-28"});
    mp.insert({"Badkal Mor", 160}); mpr.insert({160, "Badkal Mor"});
    mp.insert({"Old Faridabad", 161}); mpr.insert({161, "Old Faridabad"});
    mp.insert({"Neelam Chowk Ajronda", 162}); mpr.insert({162, "Neelam Chowk Ajronda"});
    mp.insert({"Bata Chowk", 163}); mpr.insert({163, "Bata Chowk"});
    mp.insert({"Escorts Mujesar", 164}); mpr.insert({164, "Escorts Mujesar"});
    mp.insert({"Sant Surdas", 165}); mpr.insert({165, "Sant Surdas"});
    mp.insert({"Raja Nahar Singh", 166}); mpr.insert({166, "Raja Nahar Singh"});
    mp.insert({"Botanical Garden", 167}); mpr.insert({167, "Botanical Garden"});
    mp.insert({"Okhla Bird Sanctuary", 168}); mpr.insert({168, "Okhla Bird Sanctuary"});
    mp.insert({"Kalindi Kunj", 169}); mpr.insert({169, "Kalindi Kunj"});
    mp.insert({"Jasola Vihar", 170}); mpr.insert({170, "Jasola Vihar"});
    mp.insert({"Okhla Vihar", 171}); mpr.insert({171, "Okhla Vihar"});
    mp.insert({"Jamia Milia Islamiya", 172}); mpr.insert({172, "Jamia Milia Islamiya"});
    mp.insert({"Sukhdev Vihar", 173}); mpr.insert({173, "Sukhdev Vihar"});
    mp.insert({"NSIC Okhla", 174}); mpr.insert({174, "NSIC Okhla"});
    mp.insert({"Kalkaji Mandir", 175}); mpr.insert({175, "Kalkaji Mandir"});
    mp.insert({"Nehru Enclave", 176}); mpr.insert({176, "Nehru Enclave"});
    mp.insert({"Greater Kailash", 177}); mpr.insert({177, "Greater Kailash"});
    mp.insert({"Chirag Delhi", 178}); mpr.insert({178, "Chirag Delhi"});
    mp.insert({"Panchsheel Park", 179}); mpr.insert({179, "Panchsheel Park"});
    mp.insert({"Hauz Khas", 180}); mpr.insert({180, "Hauz Khas"});
    mp.insert({"I.I.T", 181}); mpr.insert({181, "I.I.T"});
    mp.insert({"R.K.Puram", 182}); mpr.insert({182, "R.K.Puram"});
    mp.insert({"Munirka", 183}); mpr.insert({183, "Munirka"});
    mp.insert({"Vasant Vihar", 184}); mpr.insert({184, "Vasant Vihar"});
    mp.insert({"Shankar Vihar", 185}); mpr.insert({185, "Shankar Vihar"});
    mp.insert({"IGD Airport", 186}); mpr.insert({186, "IGD Airport"});
    mp.insert({"Sadar Bazar", 187}); mpr.insert({187, "Sadar Bazar"});
    mp.insert({"Palam", 188}); mpr.insert({188, "Palam"});
    mp.insert({"Dashrathpuri", 189}); mpr.insert({189, "Dashrathpuri"});
    mp.insert({"Dabri Mor", 190}); mpr.insert({190, "Dabri Mor"});
    mp.insert({"Janak Puri West", 191}); mpr.insert({191, "Janak Puri West"});
    mp.insert({"Majlis Park", 192}); mpr.insert({192, "Majlis Park"});
    mp.insert({"Azadpur", 193}); mpr.insert({193, "Azadpur"});
    mp.insert({"Shalimar Bagh", 194}); mpr.insert({194, "Shalimar Bagh"});
    mp.insert({"Netaji Subash Place", 195}); mpr.insert({195, "Netaji Subash Place"});
    mp.insert({"Shakurpur", 196}); mpr.insert({196, "Shakurpur"});
    mp.insert({"Punjabi Bagh West", 197}); mpr.insert({197, "Punjabi Bagh West"});
    mp.insert({"ESI Hospital", 198}); mpr.insert({198, "ESI Hospital"});
    mp.insert({"Rajouri Garden", 199}); mpr.insert({199, "Rajouri Garden"});
    mp.insert({"Mayapuri", 200}); mpr.insert({200, "Mayapuri"});
    mp.insert({"Naraina Vihar", 201}); mpr.insert({201, "Naraina Vihar"});
    mp.insert({"Delhi Cantt.", 202}); mpr.insert({202, "Delhi Cantt."});
    mp.insert({"Durgabai Deshmukh South Campus", 203}); mpr.insert({203, "Durgabai Deshmukh South Campus"});
    mp.insert({"Sir Vishweshwaraiah Moti Bagh", 204}); mpr.insert({204, "Sir Vishweshwaraiah Moti Bagh"});
    mp.insert({"Bhikaji Cama Place", 205}); mpr.insert({205, "Bhikaji Cama Place"});
    mp.insert({"Sarojini Nagar", 206}); mpr.insert({206, "Sarojini Nagar"});
    mp.insert({"INA", 207}); mpr.insert({207, "INA"});
    mp.insert({"South Extension", 208}); mpr.insert({208, "South Extension"});
    mp.insert({"Lajpat Nagar", 209}); mpr.insert({209, "Lajpat Nagar"});
    mp.insert({"Trilokpuri", 210}); mpr.insert({210, "Trilokpuri"});
    mp.insert({"Vinod Nagar East", 211}); mpr.insert({211, "Vinod Nagar East"});
    mp.insert({"Vinod Nagar", 212}); mpr.insert({212, "Vinod Nagar"});
    mp.insert({"I.P. Extension", 213}); mpr.insert({213, "I.P. Extension"});
    mp.insert({"Anand Vihar", 214}); mpr.insert({214, "Anand Vihar"});
    mp.insert({"Karkar Duma", 215}); mpr.insert({215, "Karkar Duma"});
    mp.insert({"Karkarduma Court", 216}); mpr.insert({216, "Karkarduma Court"});
    mp.insert({"Krishna Nagar", 217}); mpr.insert({217, "Krishna Nagar"});
    mp.insert({"East Azad Nagar", 218}); mpr.insert({218, "East Azad Nagar"});
    mp.insert({"Welcome", 219}); mpr.insert({219, "Welcome"});
    mp.insert({"Jafrabad", 220}); mpr.insert({220, "Jafrabad"});
    mp.insert({"Maujpur", 221}); mpr.insert({221, "Maujpur"});
    mp.insert({"Gokulpuri", 222}); mpr.insert({222, "Gokulpuri"});
    mp.insert({"Johri Enclave", 223}); mpr.insert({223, "Johri Enclave"});
    mp.insert({"Shiv Vihar", 224}); mpr.insert({224, "Shiv Vihar"});
    mp.insert({"Sector55-56", 225}); mpr.insert({225, "Sector55-56"});
    mp.insert({"Sector54Chowk", 226}); mpr.insert({226, "Sector54Chowk"});
    mp.insert({"Sector53-54", 227}); mpr.insert({227, "Sector53-54"});
    mp.insert({"Sector42-43", 228}); mpr.insert({228, "Sector42-43"});
    mp.insert({"Phase-I", 229}); mpr.insert({229, "Phase-I"});
    mp.insert({"Sikanderpur", 230}); mpr.insert({230, "Sikanderpur"});
    mp.insert({"Phase2", 231}); mpr.insert({231, "Phase2"});
    mp.insert({"Belvedere Towers", 232}); mpr.insert({232, "Belvedere Towers"});
    mp.insert({"Cyber City", 233}); mpr.insert({233, "Cyber City"});
    mp.insert({"Moulsari Avenue", 234}); mpr.insert({234, "Moulsari Avenue"});
    mp.insert({"Phase 3", 235}); mpr.insert({235, "Phase 3"});

    int V = 235;
    vector<vector<int> > graph(V, vector<int>(V, 0));
    // Adjacency List Creation
    // red
    addEdge(graph, mp["Rithala"], mp["Netaji Subhash Place"], 5.2, 5);
    addEdge(graph, mp["Netaji Subhash Place"], mp["Keshav Puram"], 1.2, 1);
    addEdge(graph, mp["Keshav Puram"], mp["Kanhaiya Nagar"], 0.8, 8);
    addEdge(graph, mp["Kanhaiya Nagar"], mp["Inderlok"], 1.2, 1);
    addEdge(graph, mp["Inderlok"], mp["Shastri Nagar"], 1.2, 1);
    addEdge(graph, mp["Shastri Nagar"], mp["Pratap Nagar"], 1.7, 1);
    addEdge(graph, mp["Pratap Nagar"], mp["Pulbangash"], 0.8, 8);
    addEdge(graph, mp["Pulbangash"], mp["Tis Hazari"], 0.9, 9);
    addEdge(graph, mp["Tis Hazari"], mp["Kashmere Gate"], 1.1, 1);
    addEdge(graph, mp["Kashmere Gate"], mp["Shastri Park"], 2.2, 2);
    addEdge(graph, mp["Shastri Park"], mp["Seelampur"], 1.6, 6);
    addEdge(graph, mp["Seelampur"], mp["Welcome"], 1.1, 1);
    // blue
    addEdge(graph, mp["Rajouri Garden"], mp["Ramesh Nagar"], 1, 1);
    addEdge(graph, mp["Ramesh Nagar"], mp["Moti Nagar"], 1.2, 1);
    addEdge(graph, mp["Moti Nagar"], mp["Kirti Nagar"], 1, 1);
    addEdge(graph, mp["Kirti Nagar"], mp["Shadipur"], 0.7, 7);
    addEdge(graph, mp["Shadipur"], mp["Patel Nagar"], 1.3, 2);
    addEdge(graph, mp["Patel Nagar"], mp["Rajender Place"], 0.9, 1);
    addEdge(graph, mp["Rajender Place"], mp["Karol Bagh"], 1, 2);
    addEdge(graph, mp["Karol Bagh"], mp["Rajiv Chowk"], 3.4, 3);
    addEdge(graph, mp["Rajiv Chowk"], mp["Barakhamba Road"], 0.7, 7);
    addEdge(graph, mp["Barakhamba Road"], mp["Mandi House"], 1, 2);
    addEdge(graph, mp["Mandi House"], mp["Pragati Maiden"], 0.8, 8);
    addEdge(graph, mp["Pragati Maiden"], mp["Inderprastha"], 0.8, 2);
    addEdge(graph, mp["Inderprastha"], mp["Yamuna Bank"], 1.8, 1);
    addEdge(graph, mp["Yamuna Bank"], mp["Laxmi Nagar"], 1.3, 6);
    addEdge(graph, mp["Laxmi Nagar"], mp["Nirman Vihar"], 1.1, 2);
    addEdge(graph, mp["Nirman Vihar"], mp["Preet Vihar"], 1.0, 1);
    addEdge(graph, mp["Preet Vihar"], mp["Karkar Duma"], 1.2, 1);
    addEdge(graph, mp["Karkar Duma"], mp["Anand Vihar"], 1.1, 1);
    addEdge(graph, mp["Anand Vihar"], mp["Kaushambi"], 0.8, 1);
    addEdge(graph, mp["Kaushambi"], mp["Vaishali"], 1.6, 1);
    addEdge(graph, mp["Yamuna Bank"], mp["Akshardham"], 1.3, 4);
    addEdge(graph, mp["Akshardham"], mp["Mayur Vihar Phase-1"], 1.8, 6);
    addEdge(graph, mp["Mayur Vihar Phase-1"], mp["Mayur Vihar Extention"], 1.2, 6);
    addEdge(graph, mp["Mayur Vihar Extention"], mp["New Ashok Nagar"], 0.9, 7);
    addEdge(graph, mp["New Ashok Nagar"], mp["Noida Sector-15"], 1.0, 1);
    addEdge(graph, mp["Noida Sector-15"], mp["Noida Sector-16"], 1.1, 2);
    addEdge(graph, mp["Noida Sector-16"], mp["Noida Sector-18"], 1.1, 2);
    addEdge(graph, mp["Noida Sector-18"], mp["Botanical Garden"], 1.1, 2);
    addEdge(graph, mp["Botanical Garden"], mp["Golf Course"], 1.2, 2);
    addEdge(graph, mp["Golf Course"], mp["Noida City Center"], 1.3, 3);
    // green
    addEdge(graph, mp["Madipur"], mp["Shivaji Park"], 1.1, 1);
    addEdge(graph, mp["Shivaji Park"], mp["Punjabi Bagh"], 1.6, 6);
    addEdge(graph, mp["Punjabi Bagh"], mp["Ashok Park"], 0.9, 9);
    addEdge(graph, mp["Ashok Park"], mp["Inderlok"], 1.4, 4);
    addEdge(graph, mp["Ashok Park"], mp["Sant Guru Ram Singh Marg"], 1.1, 1);
    addEdge(graph, mp["Sant Guru Ram Singh Marg"], mp["Kirti Nagar"], 1, 1);
    addEdge(graph, mp["Kashmere Gate"], mp["Lal Qila"], 1.5, 5);
    addEdge(graph, mp["Lal Qila"], mp["Jama Masjid"], 0.8, 8);
    addEdge(graph, mp["Jama Masjid"], mp["Delhi Gate"], 1.4, 4);
    addEdge(graph, mp["Delhi Gate"], mp["ITO"], 1.3, 3);
    addEdge(graph, mp["ITO"], mp["Mandi House"], 0.8, 8);
    addEdge(graph, mp["Mandi House"], mp["Janptah"], 1.4, 4);
    addEdge(graph, mp["Janptah"], mp["Central Secretariat"], 1.3, 3);
    addEdge(graph, mp["Central Secretariat"], mp["Khan Market"], 2.1, 2);
    addEdge(graph, mp["Khan Market"], mp["JL Nehru Stadium"], 1.4, 4);
    addEdge(graph, mp["JL Nehru Stadium"], mp["Jangpura"], 0.9, 9);
    // yellow
    addEdge(graph, mp["Vishwavidyalaya"], mp["Vidhan Sabha"], 1, 1);
    addEdge(graph, mp["Vidhan Sabha"], mp["Civil Lines"], 1.3, 3);
    addEdge(graph, mp["Civil Lines"], mp["Kashmere Gate"], 1.1, 1);
    addEdge(graph, mp["Kashmere Gate"], mp["Chandni Chowk"], 1.1, 1);
    addEdge(graph, mp["Chandni Chowk"], mp["Chawri Bazar"], 1, 1);
    addEdge(graph, mp["Chawri Bazar"], mp["New Delhi"], 0.8, 8);
    addEdge(graph, mp["New Delhi"], mp["Rajiv Chowk"], 1.1, 1);
    addEdge(graph, mp["Rajiv Chowk"], mp["Patel Chowk"], 1.3, 3);
    addEdge(graph, mp["Patel Chowk"], mp["Central Secretariat"], 0.9, 9);
    addEdge(graph, mp["Central Secretariat"], mp["Udyog Bhawan"], 0.3, 3);
    addEdge(graph, mp["Udyog Bhawan"], mp["Lok Kalyan Marg"], 1.6, 6);
    addEdge(graph, mp["Lok Kalyan Marg"], mp["Jor Bagh"], 1.2, 2);
    addEdge(graph, mp["Samaypur Badli"], mp["Rohini Sector - 18"], 0.8, 8);
    addEdge(graph, mp["Rohini Sector - 18"], mp["Haiderpur Badli Mor"], 1.3, 3);
    addEdge(graph, mp["Haiderpur Badli Mor"], mp["Jahangirpuri"], 1.3, 3);
    addEdge(graph, mp["Jahangirpuri"], mp["Adarsh Nagar"], 1.3, 3);
    addEdge(graph, mp["Adarsh Nagar"], mp["Azadpur"], 1.5, 5);
    addEdge(graph, mp["Azadpur"], mp["Model Town"], 1.4, 4);
    addEdge(graph, mp["Model Town"], mp["GTB Nagar"], 1.4, 4);
    addEdge(graph, mp["GTB Nagar"], mp["Vishwavidyalaya"], 0.8, 8);
    addEdge(graph, mp["Jor Bagh"], mp["INA"], 1.3, 3);
    addEdge(graph, mp["INA"], mp["AIIMS"], 0.8, 8);
    addEdge(graph, mp["AIIMS"], mp["Green Park"], 1.0, 1);
    addEdge(graph, mp["Green Park"], mp["Hauz Khas"], 1.8, 8);
    addEdge(graph, mp["Hauz Khas"], mp["Malviya Nagar"], 1.7, 7);
    addEdge(graph, mp["Malviya Nagar"], mp["Saket"], 0.9, 9);
    addEdge(graph, mp["Saket"], mp["Qutab Minar"], 1.7, 2);
    addEdge(graph, mp["Qutab Minar"], mp["Chhattarpur"], 1.3, 2);
    addEdge(graph, mp["Chhattarpur"], mp["Sultanpur"], 1.6, 2);
    addEdge(graph, mp["Sultanpur"], mp["Ghitorni"], 1.3, 2);
    addEdge(graph, mp["Ghitorni"], mp["Arjan Garh"], 2.7, 3);
    addEdge(graph, mp["Arjan Garh"], mp["Guru Dronacharya"], 2.3, 3);
    addEdge(graph, mp["Guru Dronacharya"], mp["Sikandarpur"], 1.0, 1);
    addEdge(graph, mp["Sikandarpur"], mp["MG Road"], 1.2, 1);
    addEdge(graph, mp["MG Road"], mp["IFFCO Chowk"], 1.1, 1);
    addEdge(graph, mp["IFFCO Chowk"], mp["Huda City Centre"], 1.5, 2);

    string sourcestn, deststn;

    cout << "Enter source station: ";
    getline(cin, sourcestn);

    cout << "Enter destination station: ";
    getline(cin, deststn);

    shortestPath(g, 255, mp[sourcestn], mp[deststn]);

    cout << "Fare: " << fare() << endl;
    int max_flow = ford_fulkerson(graph, mp[sourcestn], mp[deststn]);
    cout << "Maximum Flow: " << max_flow << endl;
    cout << "Time for maximum flow (assuming 1 min for 1 unit): "
         << 60 * max_flow << " seconds" << endl;

    return 0;
}
