package com.example.os;

import androidx.appcompat.app.AlertDialog;
import androidx . appcompat .app . AppCompatActivity ;

import android.content.ClipData;
import android.content.DialogInterface;
import android.graphics.drawable.Drawable;
import android .os. Bundle ;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.ListView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    ArrayList<String> taskList;
    ArrayAdapter mAdapter;
    ListView mTaskListView;

    @Override
    protected void onCreate ( Bundle savedInstanceState ) {
        super . onCreate ( savedInstanceState );
        setContentView (R. layout . activity_main );
        mTaskListView = findViewById(R.id.list_todo);
        Button delete = findViewById(R.id.task_delete);
        taskList = new ArrayList<>();
        mAdapter = new ArrayAdapter < String >( this ,
                R. layout . todo_item ,
                R.id. task_title ,
                taskList);
        mTaskListView . setAdapter ( mAdapter );
    }

    @Override
    public boolean onCreateOptionsMenu ( Menu menu ) {
        getMenuInflater () . inflate (R. menu . main_menu , menu );
        return super . onCreateOptionsMenu ( menu ) ;
    }

    @Override
    public boolean onOptionsItemSelected ( MenuItem item ) {
        switch ( item . getItemId () ) {
            case R.id. action_add_task :
                Log.d(" MainClass " , " Add a new task ");
                createDialogue();
                return true ;

            default :
                return super . onOptionsItemSelected ( item );
        }
    }

    private void addItem ( String itemText ){
        taskList . add ( itemText );
        mAdapter . notifyDataSetChanged () ;
    }
    private void removeItem ( String itemText ) {
        taskList . remove ( itemText );
        mAdapter . notifyDataSetChanged () ;
    }

    private void createDialogue(){
        final EditText taskEditText = new EditText ( this );
        AlertDialog dialog = new AlertDialog . Builder ( this )
                . setTitle (" Add a new task " )
                . setMessage ( " What do you want to do next ?")
                . setView ( taskEditText )
                . setPositiveButton (" Add " , new DialogInterface .
                        OnClickListener () {
                    @Override
                    public void onClick ( DialogInterface dialog , int which )
                    {
                        String task = String . valueOf ( taskEditText . getText ());
                        Log .d("TAG" , " Task to add : " + task ) ;
                        addItem(task);
                    }
                })
                . setNegativeButton (" Cancel " , null )
                . create () ;
        dialog . show () ;
    }

    public void deleteTask(View view) {
        int position = mTaskListView.getPositionForView(view);

        String text = taskList.get(position);
        removeItem(text);
    }
}
