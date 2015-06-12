defmodule HelloPhoenix.ApiController do
  use HelloPhoenix.Web, :controller

  plug :action

  #def index(conn, _params) do
  #  render conn, "index.html"
  #end

  def describe_subscriber(conn, _params) do
    render conn, "describe_subscriber.json"
    #render conn, "index.html"
  end
end
